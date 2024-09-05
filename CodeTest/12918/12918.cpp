#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12918

using namespace std;

bool solution(string s)
{
	const size_t s_size = s.size();

	if (4 != s_size &&
		6 != s_size)
	{
		return false;
	}

	for (const char _CurChar : s)
	{
		if ('0' > _CurChar ||
			'9' < _CurChar)
		{
			return false;
		}
	}

	return true;
}

bool isdigitsolution(string s) 
{
	const size_t s_size = s.size();

	if (4 != s_size &&
		6 != s_size)
	{
		return false;
	}

	for (const char _CurChar : s)
	{
		if (0 == std::isdigit(_CurChar))
		{
			return false;
		}
	}

	return true;
}