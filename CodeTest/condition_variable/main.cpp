#include <mutex>
#include <iostream>
#include <thread>

// condition_variable��
// ������ - �Һ��� ���� ����� ����

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

	// work1, 2, 3��� �۾��� ������ main thread �����
	if (true == Done1 && true == Done2 && true == Done3)
	{
		// main thread �����
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
		// main thread �����
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
		// main thread �����
		Condition.notify_one();
	}
}

int main()
{
	std::thread T1(work);
	std::thread T2(work2);
	std::thread T3(work3);

	std::unique_lock<std::mutex> tlock(Lock);
	// ������ true�� �� ���� unlock�� ���(sleep)
	// main thread�� wait��Ŵ
	// �ٽ� ����� lock ȹ��
	Condition.wait(tlock, []()
		{
			return true == Done1 || true == Done2 || true == Done3;
		});

	if (true == tlock.owns_lock())
	{
		std::cout << "Main Thread get lock" << std::endl;
	}

	// thread�� join or detach �� �ϳ��� �������
	// join -> thread�� ����� �� ���� ���
	// detach -> thread�� ��׶���� �и� (���μ��� ����� ������ ����)
	// T1.join();
	// T2.join();
	// T3.join();
	T1.detach();
	T2.detach();
	T3.detach();
	int x = 0;
}