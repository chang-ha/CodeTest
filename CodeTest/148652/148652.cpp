#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/148652

using namespace std;

#include <cmath>
#include <array>
int CalcuCantor(const int n, long long valueRange)
{
	// 5진수 변환
	// 1 1 0 1 1
	// 중간에 0 section이 존재하므로 1의 갯수는 0->1->2->2->3 개 
	static std::array<int, 5> quinary = { 0,1,2,2,3 };

	int answer = 0;
	int digit = 0;
	while (0 != valueRange)
	{
		if (2 == valueRange % 5)
		{
			// 5진수 변환 중 2가 나오면 0 section에 있다는 소리 -> 이전에 더해준 값들 0으로 만들어야함
			// ex) n == 2의 0 section은 10 ~ 15 사이 값
			//	-> 5진수 변환 시 20 ~ 30 이므로 2값이 나오면 이전에 더해준 1의 갯수 0으로 초기화
			// ex) n == 3의 0 section은 50 ~ 75 사이 값
			//	-> 5진수 변환 시 200 ~ 300  
			answer = 0;
		}
		answer += quinary[valueRange % 5] * static_cast<int>(std::pow(4, digit));
		++digit;
		valueRange /= 5;
	}

	return answer;
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

	return CalcuCantor(n, r) - CalcuCantor(n, l - 1);
}