#include <iostream>
#include <TimeCheck\TimeCheck.h>

#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/148652

using namespace std;

#include <cmath>
int CalcuCantor(const int n, long long valueRange)
{
	return 1;
}

#include <stdexcept>
int solution(int n, long long l, long long r)
{
	if (1 > n)
	{
		// Error
		throw std::invalid_argument("'n' is wrong argument");
	}

	if (1 > l)
	{
		// Error
		throw std::invalid_argument("'l' is wrong argument");
	}
	
	// 5^20's digit = 14, double maximum digit = 15
	if (static_cast<long long>(std::pow(5, n)) < r)
	{
		// Error
		throw std::invalid_argument("'r' is wrong argument");
	}

	if (l > r)
	{
		// Error
		throw std::invalid_argument("'l' or 'r' is wrong argument");
	}

	int answer = CalcuCantor(n, r) - CalcuCantor(n, l - 1) ;
	return answer;
}

int main() 
{
	solution(2, 5, 17);
	solution(3,5,17);
	// solution({ {40, 2900},{23, 10000},{11, 5200},{5, 5900},{40, 3100},{27, 9200},{32, 6900} }, { 1300, 1500, 1600, 4900 });
	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT ETime = CheckFunctionTime([&]()
		{
		});

	std::cout << "ATime is " << ATime.count() << " microseconds" << std::endl;
	std::cout << "BTime is " << BTime.count() << " microseconds" << std::endl;
	std::cout << "CTime is " << CTime.count() << " microseconds" << std::endl;
	std::cout << "DTime is " << DTime.count() << " microseconds" << std::endl;
	std::cout << "ETime is " << ETime.count() << " microseconds" << std::endl;
	int x = 0;
}