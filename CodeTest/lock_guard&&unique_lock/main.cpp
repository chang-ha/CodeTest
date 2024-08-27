#include <TimeCheck\TimeCheck.h>

#include <mutex>
#include <thread>

static int Count1 = 0;
static int Count2 = 0;
std::mutex Key1;
std::mutex Key2;
bool bCount1 = false;
bool bCount2 = false;

#include <iostream>

void Function1()
{
	// lock_guard는 생성자에서 lock 획득
	std::lock_guard tlock(Key1);
	++Count1;
	std::cout << "Function1" << std::endl;
	// 스코프 종료 시 lock_guard 소멸자에서 lock 해제
}

// C++ 17 이상
void Function2()
{
	// unique_lock는 생성자에서 lock 획득
	// std::unique_lock tlock(Key2);
	// 
	// if (false == tlock.owns_lock())
	// {
	// 	std::cout << "lock fail" << std::endl;
	// }
	// 
	// ++Count2;
	// tlock.unlock(); // 필요시 lock 해제 가능
	// std::cout << "Function2" << std::endl;
	// 또는 스코프 종료 시 unique_lock 소멸자에서 lock 해제

	// defer_lock : mutex를 저장하고, lock 시도 X
	// std::unique_lock tlock(Key2, std::defer_lock);
	// tlock.lock(); // lock 따로 해줘야함
	// ++Count2;
	// tlock.unlock(); // 필요시 lock 해제 가능
	// std::cout << "Function2" << std::endl;

	// adopt_lock : 이 쓰레드가 lock을 소유했고 쓰레드에서 락을 관리한다고 가정 
	// 생성전에 미리 lock을 걸어야함
	// Key2.lock();
	// std::unique_lock tlock(Key2, std::adopt_lock);
	// ++Count2;
	// tlock.unlock(); // 필요시 lock 해제 가능
	// std::cout << "Function2" << std::endl;

	// try_to_lock : mutex에 lock 시도
	// 공부 추가 필요
	std::unique_lock tlock(Key2, std::try_to_lock);
	bool LockSuccess = false;
	if (false == tlock.owns_lock())
	{
	 LockSuccess = tlock.try_lock();
	}

	if (false == LockSuccess)
	{
	 std::cout << "Lock Fail \n";
	}

 	++Count2;
 	std::cout << "Function2" << std::endl;
}

void Function()
{
	std::unique_lock tlock(Key1, std::try_to_lock);
	
	if (tlock)
	{

	}

	if (false == tlock.owns_lock())
	{
		bool LockSuccss = tlock.try_lock();
		std::cout << "Try Lock " << std::endl;
	}
}

int main()
{
	Key1.lock();
	std::thread T1(Function);
	T1.join();
	// std::chrono::steady_clock::time_point BStart = std::chrono::high_resolution_clock::now();
	// TIME_UNIT BTime = CheckFunctionTime([&]()
	// 	{
	// 		std::thread t3(Function2);
	// 		t3.detach();
	// 		std::thread t4(Function2);
	// 		t4.detach();
	// 	}, 1000);
	// 
	// std::chrono::steady_clock::time_point AStart = std::chrono::high_resolution_clock::now();
	// TIME_UNIT ATime = CheckFunctionTime([&]()
	// 	{
	// 		std::thread t1(Function1);
	// 		t1.detach();
	// 		std::thread t2(Function1);
	// 		t2.detach();
	// 	}, 1000);
	// 
	// std::chrono::steady_clock::time_point AEnd;
	// std::chrono::steady_clock::time_point BEnd;
	// while (true)
	// {
	// 	if (false == bCount1 && 2000 == Count1)
	// 	{
	// 		AEnd = std::chrono::high_resolution_clock::now();
	// 		bCount1 = true;
	// 	}
	// 
	// 	if (false == bCount2 && 2000 == Count2)
	// 	{
	// 		BEnd = std::chrono::high_resolution_clock::now();
	// 		bCount2 = true;
	// 	}
	// 
	// 	if (true == bCount2 && true == bCount1)
	// 	{
	// 		break;
	// 	}
	// }
	// 
	// TIME_UNIT AResult = std::chrono::duration_cast<TIME_UNIT>(AEnd - AStart);
	// TIME_UNIT BResult = std::chrono::duration_cast<TIME_UNIT>(BEnd - BStart);
	// 
	// std::cout << "ATime is " << AResult.count() << " microseconds" << std::endl;
	// std::cout << "BTime is " << BResult.count() << " microseconds" << std::endl;
	// int x = 0;
	Key1.unlock();
}