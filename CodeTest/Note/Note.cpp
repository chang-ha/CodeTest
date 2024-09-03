#include <iostream>
#include <TimeCheck\TimeCheck.h>
#include <string>
#include <vector>

using namespace std;
double solution(vector<int> arr)
{
	double answer = 0;
	long long Sum = 0;

	for (const int _CurValue : arr)
	{
		Sum += _CurValue;
	}

	answer = static_cast<double>(Sum) / arr.size();

	return answer;
}

int main()
{
	solution({1,2,3,4,5,6});
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