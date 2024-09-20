#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/42747

using namespace std;

#include <algorithm>

// 3 0 6 1 5
// sort : 6 5 3 1 0 
// i = 0 >= a[0] = 6 ? X	<< 6(a[i])보다 큰 논문 0(i)개 
// i = 1 >= a[1] = 5 ? X	<< 5(a[i])보다 큰 논문 1(i)개 (&& 모든 논문이 6보다 크거나 같음)
// i = 2 >= a[2] = 3 ? X	<< 3(a[i])보다 큰 논문 2(i)개 (&& 모든 논문이 5보다 크거나 같음)
// i = 3 >= a[3] = 1 ? O	<< 1(a[i])보다 큰 논문 3(i)개 (&& 모든 논문이 3보다 크거나 같음)
//								-> 조건이 가장 먼저 걸리는 값이 최대값
// return 3

// 0
// 0 >= 0 << 0보다 큰 논문 0개
// return 0

// 4 3
// 1 > 4
// 2 > 3
// 모든 논문이 size(2)보다 큼
// return 2;

// 999 998 997 996 995
// i = 0 >= a[0] = 999 ? X
// i = 1 >= a[1] = 998 ? X
// i = 2 >= a[2] = 997 ? X
// i = 3 >= a[3] = 996 ? X
// i = 4 >= a[4] = 995 ? X
// 모든 논문이 size(5)보다 큼
// return 5

// 9 7 6 2 1

int solution(vector<int> citations)
{
	std::sort(citations.begin(), citations.end(), std::greater<int>());

	const int citations_size = static_cast<int>(citations.size());
	for (int i = 0; i < citations_size; i++)
	{
		if (i >= citations[i])
		{
			return i;
		}
	}

	return citations_size;
}

// 3 0 6 1 5
// l_sort : 0 1 3 5 6
// 0 -> 5
// 1 -> 4
// 3 -> 3
// 5 -> 2
// 6 -> 1

// 3 4 
// 3 -> 2
// 4 -> 1

// 1 11 111 1111
// 1 -> 4
// 11 -> 3
// 111 -> 2
// 1111 -> 1

// 3 5 11 6 1 5 3 3 1 41
// 1 1 3 3 3 5 5 6 11 41
int solution(vector<int> citations)
{
	std::sort(citations.begin(), citations.end());

	const size_t citations_size = citations.size();
	if (0 == citations_size)
	{
		return 0;
	}

	if (citations[0] >= citations_size)
	{
		return static_cast<int>(citations_size);
	}

	int answer = 0;
	for (size_t i = 0; i < citations_size;)
	{
		if (answer > citations[i])
		{
			++i;
			continue;
		}
		else if (citations_size - i >= answer)
		{
			++answer;
		}
		else
		{
			break;
		}
	}

	return answer - 1;
}
