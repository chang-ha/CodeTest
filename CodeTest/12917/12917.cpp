#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/12917

using namespace std;

#include <algorithm>
string sortsolution(string s)
{
	std::string answer = s;
	std::sort(answer.begin(), answer.end(), std::greater<char>());
	return answer;
}

string solution(string s)
{
	std::string answer = "";
	std::vector<int> CharVector(52 + 6, 0); // (A ~ Z + a ~ z) + blank space('Z' to 'a')

	for (const char _CurChar : s)
	{
		if (0 == std::isalpha(_CurChar))
		{
			return "Contains Not Alpha";
		}

		CharVector[_CurChar - 'A'] += 1;
	}

	const int CharVector_size = static_cast<int>(CharVector.size());
	for (int i = CharVector_size - 1; i >= 0; --i)
	{
		answer.append(CharVector[i], i + 'A');
	}

	return answer;
}

// reverse_iterator -> 직관적이지 않음
// rbegin, rend로 sort시 매우 느려짐 ( != reverse_iterator 자체가 느리다는건 아님)
string rsortsolution(string s)
{
	std::string answer = s;
	std::sort(answer.rbegin(), answer.rend());
	return answer;
}