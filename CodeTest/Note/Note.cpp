#include <TimeCheck\TimeCheck.h>

#include <thread>
#include <mutex>
#include <iostream>

static int Count1 = 0;
static int Count2 = 0;
std::mutex Key1;
std::mutex Key2;
bool bCount1 = false;
bool bCount2 = false;

void Function1()
{
	std::lock_guard tlock(Key1);
	++Count1;
	std::cout << "Function1" << std::endl;
}

void Function2()
{
	std::unique_lock tlock(Key2);
	++Count2;
	tlock.unlock();
	std::cout << "Function2" << std::endl;
}

int main()
{
	std::chrono::steady_clock::time_point BStart = std::chrono::high_resolution_clock::now();
	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
			std::thread t3(Function2);
			t3.detach();
			std::thread t4(Function2);
			t4.detach();
		}, 1000);

	std::chrono::steady_clock::time_point AStart = std::chrono::high_resolution_clock::now();
	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
			std::thread t1(Function1);
			t1.detach();
			std::thread t2(Function1);
			t2.detach();
		}, 1000);

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT ETime = CheckFunctionTime([&]()
		{
		});

	std::chrono::steady_clock::time_point AEnd;
	std::chrono::steady_clock::time_point BEnd;
	while (true)
	{
		if (false == bCount1 && 2000 == Count1)
		{
			AEnd = std::chrono::high_resolution_clock::now();
			bCount1 = true;
		}

		if (false == bCount2 && 2000 == Count2)
		{
			BEnd = std::chrono::high_resolution_clock::now();
			bCount2 = true;
		}

		if (true == bCount2 && true == bCount1)
		{
			break;
		}
	}

	TIME_UNIT AResult = std::chrono::duration_cast<TIME_UNIT>(AEnd - AStart);
	TIME_UNIT BResult = std::chrono::duration_cast<TIME_UNIT>(BEnd - BStart);

	std::cout << "ATime is " << ATime.count() << " microseconds" << std::endl;
	std::cout << "BTime is " << BTime.count() << " microseconds" << std::endl;
	std::cout << "CTime is " << CTime.count() << " microseconds" << std::endl;
	std::cout << "DTime is " << DTime.count() << " microseconds" << std::endl;
	std::cout << "ETime is " << ETime.count() << " microseconds" << std::endl;
	int x = 0;
}