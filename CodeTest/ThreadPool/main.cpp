#include <vector>
#include <thread>
#include <functional>
#include <condition_variable>
#include <future>
#include <mutex>
#include <queue>

// IOCP thread pool 대신 자체적으로 tread pool 생성
//	-> IOCP는 windows에서만 사용가능
// ThreadPool 생성 이유?
// 1. 매번 Thread를 생성하고 소멸시키는 오버헤드 제거

class ThreadPool
{
public:
	// size_t = 0 : Calcu CPU's Total Threads
	ThreadPool(size_t = 0);
	~ThreadPool();

	void Pushjob(std::function<void()> job);

	// 쓰레드 업무가 인자가 필요할 수 있기 떄문에, 사용자 편의를 위해 아래와 같이 작성
	// F = 실행함수
	// Args = 함수 인자 (가변인자)
	template<class F, class... Args>
	auto enqueue(F&& function, Args&&... args)
		-> std::future<typename std::result_of<F(Args...)>::type>; // 후행 반환 형식

private:
	std::vector<std::thread> Workers;
	// 모든 thread가 접근할 수 있는 업무 컨테이너
	// FIFO task로 수행 
	// 다른 다양한 처리형태 존재
	//	 1. 가장 먼저 들어온 업무 처리 (FIFO)
	//	 2. 가장 최신에 들어온 업무 처리 (LIFO)
	//	 3. 가장 간단한 업무 처리
	// 등등...
	// race condition(경쟁 상태) 문제 해결 필요
	//   1. Mutual exclsuion (상호 배제 == mutex) -> 한 쓰레드가 공용 데이터를 사용중이면 다른 쓰레드가 사용하지 못하게 막는 문제
	//	 2. Dead Lock (데드락)
	//			(1) 두 쓰레드가 각각 2개 이상의 자원을 필요로 하는데, 서로 1개씩 가지고 있는 경우
	//			(2) 다른 쓰레드가 영구히 Lock을 해제하지 않는 경우
	//   3. Starvation (기아상태 == 영구 블록) -> 서로가 서로의 작업 결과물을 기다리는 상태
	std::queue<std::function<void()>> tasks;
	void Threadtask();
	// race condition 해결 방안으로 1. Mutex, 2. Semaphore가 존재
	// 여기선 Mutex 사용
	// 재귀 필요 시 recursive_mutex
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
	//			std::cout << "thread 업무 중" << std::endl;
	//		});
	//	std::cout << "thread jou push 성공" << std::endl;
	//}
	//catch (const std::runtime_error& _errorMessage)
	//{
	//	std::cout << _errorMessage.what() << std::endl;
	//	std::cout << "thread job push 실패" << std::endl;
	//}

	//tThreadPool.EndThreadPool();

	//try
	//{
	//	tThreadPool.Pushjob([]()
	//		{
	//		});
	//	std::cout << "thread jou push 성공" << std::endl;
	//}
	//catch (const std::runtime_error& _errorMessage)
	//{
	//	std::cout << _errorMessage.what() << std::endl;
	//	std::cout << "thread job push 실패" << std::endl;
	//}
}

void ThreadPool::Threadtask()
{
	// 쓰레드 업무
	// while문 돌면서 업무 존재 시 업무 수행 / 업무 없을 시 대기
	while (true)
	{
		// 해당 쓰레드의 업무
		std::function<void()> task;

		// Scope 생성
		{
			// 도중에 lock을 따로 하거나 해제하지 않을땐, std::lock_guard를 사용해도 됨
			// 하지만 contidion_variable은 unique_lock만 사용 가능
			// std::lock_guard<std::mutex> tlock(this->queue_mutex);
			std::unique_lock<std::mutex> tlock(this->queue_mutex);

			// thread 대기 (조건이 true면 lock을 해제하고 대기상태로 진입)
			this->condition.wait(tlock, [this]()
				{
					// thread pool이 stop이거나 업무가 비어있지 않으면 대기
					return this->Stop || !this->tasks.empty();
				});

			// thread pool이 stop && 업무 전부 끝났으면 return;
			if (this->Stop && this->tasks.empty())
			{
				break;
			}

			// 맨 앞의 업무 가져옴
			// 오버헤드 최소화를 위해 move사용
			task = std::move(this->tasks.front());
			this->tasks.pop();
		}

		// 업무 수행
		task();
	}
}

#include <Windows.h>
inline ThreadPool::ThreadPool(size_t thread_count)
	: Stop(false)
{
	// 자동으로 CPU 스레드 갯수( != CPU core 갯수)를 참고해서 thread 생성
	// 내 컴퓨터의 경우
	// 성능 코어 4 + 효율 코어 8개 = 총 12개 코어
	// 총 스레드 = 16 (하이퍼 스레딩 적용)
	if (0 == thread_count)
	{
		SYSTEM_INFO sysinfo;
		GetSystemInfo(&sysinfo);
		// 총 스레드
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
				// thread를 emplace_back
				this->Threadtask();
			});
	}
}

// 아래 함수는 함수가 Argument를 받을 수 없음
// std::bind로 넘겨줄 수 있지만 사용자가 불편함
// 그래서 아래 함수(enqueue) 구현
void ThreadPool::Pushjob(std::function<void()> job)
{
	if (true == Stop)
	{
		throw std::runtime_error("ThreadPool 정지 중");
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
		throw std::runtime_error("ThreadPool 정지 중");
	}

	// promise와 future 사용
	// 여러 thread가 공유필요시 std::shared_future 사용 (여기선 필요 X)
	using FunctionReturn = typename std::result_of<F(Args...)>::type; 
	// == std::future<return type of function> == function의 리턴값

	// shared_ptr로 task 파괴 방지
	auto task = std::make_shared<std::packaged_task<FunctionReturn()>>(std::bind(function, args...));

	std::future<FunctionReturn> Result = task->get_future();

	{
		std::unique_lock<std::mutex> tlock(queue_mutex);
		tasks.push([task]() { (*task)(); });
	}

	// 업무가 들어왔으니 대기중인 쓰레드 1개 꺠움
	condition.notify_one();
	return Result;
}

inline void ThreadPool::EndThreadPool()
{
	// lock_guard 사용과 동일
	// std::lock_guard<std::mutex> tlock(queue_mutex);
	std::unique_lock<std::mutex> tlock(queue_mutex);
	// Thread Pool stop
	Stop = true;
}

inline ThreadPool::~ThreadPool()
{
	EndThreadPool();

	// 모든 thread를 깨움
	// thread pool을 stop했으니 모두 소멸되라고 깨움(현재 업무가 없는 쓰레드들은 수면 중)
	condition.notify_all();

	// 업무가 남아있으면 업무 마저 끝내고 소멸될 때 까지 대기
	for (std::thread& CurWorker : Workers)
	{
		// 모든 thread가 업무 끝날때 까지 대기
		CurWorker.join();
	}

	// 모든 thread 소멸
	std::cout << "Thread Pool 소멸" << std::endl;
}