#include <iostream>
#include <TimeCheck\TimeCheck.h>

#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/72411

using namespace std;

#include <algorithm>
vector<string> solution(vector<string> orders, vector<int> course)
{
	vector<string> answer;

	// std::next_permutation 내부에서 swap & reverse 하기 때문에 const 불가능
	// 원리 : 오름차순 -> 내림차순으로 변경하는 알고리즘
	// 마지막, --마지막 비교 -> 작으면 true & 스왑, 크거나 같으면 false
	for (std::string& order : orders)
	{
		// 정렬 해줘야 모든 순열 구할 수 있음
		// 내부에서 a[i-1] > a[i]을 만족하는 가장 큰 i값을 찾기 때문에
		// 정렬되어 있지 않으면, 중간에 해당 조건에 걸리는 순간부터 순열을 구하게 됨
		std::sort(order.begin(), order.end());
		// next_permutation을 하는 순간에 order가 바뀌기 때문에
		// do로 가장 첫 번째 조합으로 실행하고 next_permutation 실행
		// 마지막에 reverse를 해주기 때문에 다시 원래 형태로 되돌아옴 (단, 정렬되어있지 않으면 형태 바뀜)
		do
		{
			std::string::iterator StartIter = order.begin();
			std::string::iterator EndIter = order.end();
			for (; StartIter != EndIter; ++StartIter)
			{
				std::cout << *StartIter;
			}
			std::cout << std::endl;
		} while (std::next_permutation(order.begin(), order.end()));

		std::string::iterator StartIter = order.begin();
		std::string::iterator EndIter = order.end();
		for (; StartIter != EndIter; ++StartIter)
		{
			std::cout << *StartIter;
		}
		std::cout << std::endl;
	}



	return answer;
}

int main() 
{
	solution({ "AFBCG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
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