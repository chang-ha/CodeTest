#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/12926

using namespace std;

string solution(string s, int n)
{
	string answer = s;

	// n이 26(A ~ Z)넘어서면 나머지만 계산
	n %= 26;

	const size_t s_size = s.size();
	for (size_t i = 0; i < s_size; i++)
	{
		if (false == std::isalpha(answer[i]))
		{
			continue;
		}

		unsigned char CalcuChar = answer[i] + n;

		if ('z' < CalcuChar ||
			('Z' < CalcuChar && 0 != std::isupper(answer[i])))
		{
			CalcuChar -= 26;
		}

		answer[i] = CalcuChar;
	}

	return answer;
}