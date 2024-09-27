#include <iostream>
#include <TimeCheck\TimeCheck.h>

#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/64065

using namespace std;

// 1�� ���� , = 0
// 2�� ���� , = 0 + ���� �޸� 1 + 2�� ���� ���� �޸� 1 = 2
// 3�� ���� , = 0 + 2�� ���� 2 + ���� �޸� 1 + 3�� ���� ���� �޸� 2 = 0 + 2 + 3
// 4�� ���� , = 0 + 2 + 3 + ���� �޸� 1 + 4�� ���� ���� �޸� 3 = 0 + 2 + 3 + 4 

// n(n+1) / 2 = comma + 1
// n(n+1) = 2X + 2
// n^2 + n = 2 X + 2 
// n(n+1) = 110
// 

#include <algorithm>
vector<int> solution(string s)
{
	vector<int> answer;
	int countOfComma = std::count(s.begin(), s.end(), ',');
	// answer.reserve();

	return answer;
}

int main() 
{
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