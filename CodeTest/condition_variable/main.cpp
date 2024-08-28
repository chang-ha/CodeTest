#include <mutex>
#include <iostream>
#include <thread>

// condition_variable은
// 생성자 - 소비자 패턴 만들기 유용

std::mutex Lock;
std::condition_variable Condition;
bool Done1 = false;
bool Done2 = false;
bool Done3 = false;
std::string Data;

void work()
{
	{
		std::lock_guard<std::mutex> tlock(Lock);
		Data = "Data Info";
		std::cout << "work1" << std::endl;
		std::cout << "Data : " << Data << std::endl;
		Done1 = true;
	}

	// work1, 2, 3모든 작업이 끝나면 main thread 깨우기
	if (true == Done1 && true == Done2 && true == Done3)
	{
		// main thread 깨우기
		Condition.notify_one();
	}
}

void work2()
{
	{
		std::unique_lock<std::mutex> tlock(Lock);

		std::cout << "work2" << std::endl;
		Data = "Data Info2";
		std::cout << "Data :" << Data << std::endl;
		Done2 = true;

	}

	if (true == Done1 && true == Done2 && true == Done3)
	{
		// main thread 깨우기
		Condition.notify_one();
	}
}

void work3()
{
	{
		std::unique_lock<std::mutex> tlock(Lock);

		std::cout << "work3" << std::endl;
		Data = "Data Info3";
		std::cout << "Data :" << Data << std::endl;
		Done3 = true;

	}

	if (true == Done1 && true == Done2 && true == Done3)
	{
		// main thread 깨우기
		Condition.notify_one();
	}
}

int main()
{
	std::thread T1(work);
	std::thread T2(work2);
	std::thread T3(work3);

	std::unique_lock<std::mutex> tlock(Lock);
	// 조건이 true일 떄 까지 unlock후 대기(sleep)
	// main thread를 wait시킴
	// 다시 깨우면 lock 획득
	Condition.wait(tlock, []()
		{
			return true == Done1 || true == Done2 || true == Done3;
		});

	if (true == tlock.owns_lock())
	{
		std::cout << "Main Thread get lock" << std::endl;
	}

	T1.join();
	T2.join();
	T3.join();
	int x = 0;
}