#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
	int answer = 0;

	char FirstWord = ' ';
	int FirstWordCount = 0;
	int OtherWordCount = 0;

	for (const char _CurChar : s)
	{
		if (' ' == FirstWord)
		{
			FirstWord = _CurChar;
		}

		if (_CurChar == FirstWord)
		{
			++FirstWordCount;
		}
		else
		{
			++OtherWordCount;
		}

		if (FirstWordCount == OtherWordCount)
		{
			++answer;
			FirstWord = ' ';
			FirstWordCount = 0;
			OtherWordCount = 0;
		}
	}

	// 문자가 분해되지 않음
	if (' ' != FirstWord)
	{
		++answer;
	}

	return answer;
}