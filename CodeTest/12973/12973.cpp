#include<string>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12973
using namespace std;

#include <stack>
int solution(string s)
{
	std::stack<char> pairchar;

	for (const char CurChar : s)
	{
		if (false == pairchar.empty() &&
			CurChar == pairchar.top())
		{
			pairchar.pop();
			continue;
		}

		pairchar.push(CurChar);
	}

	return pairchar.empty() ? 1 : 0;
}