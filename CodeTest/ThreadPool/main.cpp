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
	ThreadPool(const size_t);
	~ThreadPool();

	void Pushjob(std::function<void()> job);

	// ������ ������ ���ڰ� �ʿ��� �� �ֱ� ������, ����� ���Ǹ� ���� �Ʒ��� ���� �ۼ�
	// F = �����Լ�
	// Args = �Լ� ���� (��������)
	template<class F, class... Args>
	auto enqueue(F&& f, Args&&... args) 
		-> std::future<typename std::result_of<F(Args...)>::type>; // ���� ��ȯ ����

	void EndThreadPool();

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
	//   1. Mutual exclsuion (��ȣ ����) -> �� �����尡 ���� �����͸� ������̸� �ٸ� �����尡 ������� ���ϰ� ���� ����
	//	 2. Dead Lock (�����)
	//			(1) �� �����尡 ���� 2�� �̻��� �ڿ��� �ʿ�� �ϴµ�, ���� 1���� ������ �ִ� ���
	//			(2) �ٸ� �����尡 ������ Lock�� �������� �ʴ� ���
	//   3. Starvation (��ƻ��� == ���� ���) -> ���ΰ� ������ �۾� ������� ��ٸ��� ����
	std::queue<std::function<void()>> tasks;
	void Threadtask();
	// race condition �ذ� ������� 1. Mutex, 2. Semaphore�� ����
	// ���⼱ Mutex ���
	std::mutex queue_mutex;
	std::condition_variable condition;
	bool Stop;
};

#include <iostream>
int Calcu_Add(int A, int B)
{
	int Result = A + B;
	std::cout << Result << std::endl;
	return Result;
}

int main()
{
	ThreadPool tThreadPool(4);

	try
	{
		tThreadPool.Pushjob([]()
			{
				std::cout << "thread ���� ��" << std::endl;
			});
		std::cout << "thread jou push ����" << std::endl;
	}
	catch (const std::runtime_error& _errorMessage)
	{
		std::cout << _errorMessage.what() << std::endl;
		std::cout << "thread job push ����" << std::endl;
	}

	tThreadPool.Pushjob(std::bind(Calcu_Add, 1, 2));

	tThreadPool.EndThreadPool();

	try
	{
		tThreadPool.Pushjob([]()
			{
			});
		std::cout << "thread jou push ����" << std::endl;
	}
	catch (const std::runtime_error& _errorMessage)
	{
		std::cout << _errorMessage.what() << std::endl;
		std::cout << "thread job push ����" << std::endl;
	}
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

inline ThreadPool::ThreadPool(const size_t thread_count)
	: Stop(false)
{
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
auto ThreadPool::enqueue(F&& f, Args&&... args)
	-> std::future<typename std::result_of<F(Args...)>::type>
{
	using FunctionReturn = typename std::result_of<F(Args...)>::type;

	if (true == Stop)
	{
		std::runtime_error("ThreadPool ���� ��");
	}

	{
		std::unique_lock<std::mutex> tlock(queue_mutex);
		this->tasks
	}

	// ������ �������� ������� ������ 1�� �ƿ�
	condition.notify_one();
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