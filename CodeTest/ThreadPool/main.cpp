#include <vector>
#include <thread>
#include <functional>
#include <condition_variable>
#include <future>
#include <mutex>
#include <queue>

// IOCP thread pool ��� ��ü������ tread pool ����
//	-> IOCP�� windows������ ��밡��
// ThreadPool ���� ����?
// 1. �Ź� Thread�� �����ϰ� �Ҹ��Ű�� ������� ����

class ThreadPool
{
public:
	// size_t = 0 : Calcu CPU's Total Threads
	ThreadPool(size_t = 0);
	~ThreadPool();

	void Pushjob(std::function<void()> job);

	// ������ ������ ���ڰ� �ʿ��� �� �ֱ� ������, ����� ���Ǹ� ���� �Ʒ��� ���� �ۼ�
	// F = �����Լ�
	// Args = �Լ� ���� (��������)
	template<class F, class... Args>
	auto enqueue(F&& function, Args&&... args)
		-> std::future<typename std::result_of<F(Args...)>::type>; // ���� ��ȯ ����

private:
	std::vector<std::thread> Workers;
	// ��� thread�� ������ �� �ִ� ���� �����̳�
	// FIFO task�� ���� 
	// �ٸ� �پ��� ó������ ����
	//	 1. ���� ���� ���� ���� ó�� (FIFO)
	//	 2. ���� �ֽſ� ���� ���� ó�� (LIFO)
	//	 3. ���� ������ ���� ó��
	// ���...
	// race condition(���� ����) ���� �ذ� �ʿ�
	//   1. Mutual exclsuion (��ȣ ���� == mutex) -> �� �����尡 ���� �����͸� ������̸� �ٸ� �����尡 ������� ���ϰ� ���� ����
	//	 2. Dead Lock (�����)
	//			(1) �� �����尡 ���� 2�� �̻��� �ڿ��� �ʿ�� �ϴµ�, ���� 1���� ������ �ִ� ���
	//			(2) �ٸ� �����尡 ������ Lock�� �������� �ʴ� ���
	//   3. Starvation (��ƻ��� == ���� ���) -> ���ΰ� ������ �۾� ������� ��ٸ��� ����
	std::queue<std::function<void()>> tasks;
	void Threadtask();
	// race condition �ذ� ������� 1. Mutex, 2. Semaphore�� ����
	// ���⼱ Mutex ���
	// ��� �ʿ� �� recursive_mutex
	std::mutex queue_mutex;
	std::condition_variable condition;
	void EndThreadPool();
	bool Stop;
};

#include <iostream>
int Calcu_Add(int A, int B)
{
	int Result = A + B;
	std::cout << Result << std::endl;
	return Result;
}

int Infinity()
{
	int a = 0;
	while (a < 1000)
	{
		++a;
		std::cout << "while Looping\n";
	}
	return a;
}

void voidInfinity()
{
	for (size_t i = 0; i < 100; i++)
	{

	}
}

int main()
{
	ThreadPool tThreadPool;
	std::vector<std::future<int>> futures;
	for (int i = 0; i < 10; i++) {
		futures.emplace_back(tThreadPool.enqueue(Calcu_Add, 1, i));
	}

	int a = 0;

	// for (int i = 0; i < 10; i++)
	// {
	// 	futures[i].wait();
	// }

	bool CalcuEnd = false;

	while (false == CalcuEnd)
	{
		int futures_size = static_cast<int>(futures.size());
		for (int i = 0; i < futures_size; i++)
		{
			CalcuEnd = futures[i]._Is_ready();
			if (false == CalcuEnd)
			{
				break;
			}
			CalcuEnd = true;
		}
	}
	int b = 0;
	// auto Result = tThreadPool.enqueue(Infinity);
	// 
	// auto AResult = tThreadPool.enqueue(voidInfinity);
	// Result.wait();
	// int a = 0;
	// 
	// AResult.wait();
	// int b = 0;
	//try
	//{
	//	tThreadPool.Pushjob([]()
	//		{
	//			std::cout << "thread ���� ��" << std::endl;
	//		});
	//	std::cout << "thread jou push ����" << std::endl;
	//}
	//catch (const std::runtime_error& _errorMessage)
	//{
	//	std::cout << _errorMessage.what() << std::endl;
	//	std::cout << "thread job push ����" << std::endl;
	//}

	//tThreadPool.EndThreadPool();

	//try
	//{
	//	tThreadPool.Pushjob([]()
	//		{
	//		});
	//	std::cout << "thread jou push ����" << std::endl;
	//}
	//catch (const std::runtime_error& _errorMessage)
	//{
	//	std::cout << _errorMessage.what() << std::endl;
	//	std::cout << "thread job push ����" << std::endl;
	//}
}

void ThreadPool::Threadtask()
{
	// ������ ����
	// while�� ���鼭 ���� ���� �� ���� ���� / ���� ���� �� ���
	while (true)
	{
		// �ش� �������� ����
		std::function<void()> task;

		// Scope ����
		{
			// ���߿� lock�� ���� �ϰų� �������� ������, std::lock_guard�� ����ص� ��
			// ������ contidion_variable�� unique_lock�� ��� ����
			// std::lock_guard<std::mutex> tlock(this->queue_mutex);
			std::unique_lock<std::mutex> tlock(this->queue_mutex);

			// thread ��� (������ true�� lock�� �����ϰ� �����·� ����)
			this->condition.wait(tlock, [this]()
				{
					// thread pool�� stop�̰ų� ������ ������� ������ ���
					return this->Stop || !this->tasks.empty();
				});

			// thread pool�� stop && ���� ���� �������� return;
			if (this->Stop && this->tasks.empty())
			{
				break;
			}

			// �� ���� ���� ������
			// ������� �ּ�ȭ�� ���� move���
			task = std::move(this->tasks.front());
			this->tasks.pop();
		}

		// ���� ����
		task();
	}
}

#include <Windows.h>
inline ThreadPool::ThreadPool(size_t thread_count)
	: Stop(false)
{
	// �ڵ����� CPU ������ ����( != CPU core ����)�� �����ؼ� thread ����
	// �� ��ǻ���� ���
	// ���� �ھ� 4 + ȿ�� �ھ� 8�� = �� 12�� �ھ�
	// �� ������ = 16 (������ ������ ����)
	if (0 == thread_count)
	{
		SYSTEM_INFO sysinfo;
		GetSystemInfo(&sysinfo);
		// �� ������
		thread_count = sysinfo.dwNumberOfProcessors;
	}

	Workers.reserve(thread_count);
	for (size_t i = 0; i < thread_count; i++)
	{
		// std::thread tThread([this]()
		// 	{
		// 		this->Threadtask();
		// 	});
		// Workers.push_back(tThread);
		Workers.emplace_back([this]()
			{
				// thread�� emplace_back
				this->Threadtask();
			});
	}
}

// �Ʒ� �Լ��� �Լ��� Argument�� ���� �� ����
// std::bind�� �Ѱ��� �� ������ ����ڰ� ������
// �׷��� �Ʒ� �Լ�(enqueue) ����
void ThreadPool::Pushjob(std::function<void()> job)
{
	if (true == Stop)
	{
		throw std::runtime_error("ThreadPool ���� ��");
	}

	{
		std::unique_lock<std::mutex> tlock(queue_mutex);
		tasks.push(std::move(job));
	}
	condition.notify_one();
}

template<class F, class... Args>
auto ThreadPool::enqueue(F&& function, Args&&... args)
	-> std::future<typename std::result_of<F(Args...)>::type>
{
	if (true == Stop)
	{
		throw std::runtime_error("ThreadPool ���� ��");
	}

	// promise�� future ���
	// ���� thread�� �����ʿ�� std::shared_future ��� (���⼱ �ʿ� X)
	using FunctionReturn = typename std::result_of<F(Args...)>::type; 
	// == std::future<return type of function> == function�� ���ϰ�

	// shared_ptr�� task �ı� ����
	auto task = std::make_shared<std::packaged_task<FunctionReturn()>>(std::bind(function, args...));

	std::future<FunctionReturn> Result = task->get_future();

	{
		std::unique_lock<std::mutex> tlock(queue_mutex);
		tasks.push([task]() { (*task)(); });
	}

	// ������ �������� ������� ������ 1�� �ƿ�
	condition.notify_one();
	return Result;
}

inline void ThreadPool::EndThreadPool()
{
	// lock_guard ���� ����
	// std::lock_guard<std::mutex> tlock(queue_mutex);
	std::unique_lock<std::mutex> tlock(queue_mutex);
	// Thread Pool stop
	Stop = true;
}

inline ThreadPool::~ThreadPool()
{
	EndThreadPool();

	// ��� thread�� ����
	// thread pool�� stop������ ��� �Ҹ�Ƕ�� ����(���� ������ ���� ��������� ���� ��)
	condition.notify_all();

	// ������ ���������� ���� ���� ������ �Ҹ�� �� ���� ���
	for (std::thread& CurWorker : Workers)
	{
		// ��� thread�� ���� ������ ���� ���
		CurWorker.join();
	}

	// ��� thread �Ҹ�
	std::cout << "Thread Pool �Ҹ�" << std::endl;
}