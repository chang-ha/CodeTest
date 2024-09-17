#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/76502

using namespace std;

#include <stack>
#include <unordered_map>
bool Checkstring(const std::string& Double_s, const size_t StartIndex, const size_t s_size)
{
	static std::unordered_map<char, char> CharPair = { {')', '('}, {'}', '{'}, {']', '['} };

	std::stack<char> CharStack;
	if (StartIndex + s_size >= Double_s.size())
	{
		return false;
	}

	for (size_t i = 0; i < s_size; i++)
	{
		const char CurChar = Double_s[StartIndex + i];

		if ('(' == CurChar || '{' == CurChar || '[' == CurChar)
		{
			CharStack.push(CurChar);
			continue;
		}

		if (true == CharStack.empty())
		{
			return false;
		}

		if (CharStack.top() != CharPair[CurChar])
		{
			return false;
		}

		CharStack.pop();
	}

	return true == CharStack.empty() ? true : false;
}

#include <stdexcept>
int solution(string s)
{
	int answer = 0;
	std::string Double_s = s + s;


	const size_t Double_s_size = Double_s.size();
	const size_t s_size = Double_s_size / 2;

	for (size_t StartIndex = 0; StartIndex < s_size; StartIndex++)
	{
		if (true == Checkstring(Double_s, StartIndex, s_size))
		{
			++answer;
		}
	}

	return answer;
}