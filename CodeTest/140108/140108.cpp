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
		// 첫 번째 글자
		if (' ' == FirstWord)
		{
			FirstWord = _CurChar;
		}

		// 현재 글자와 첫 글자 같으면
		if (_CurChar == FirstWord)
		{
			++FirstWordCount;
		}
		else
		{
			// 현재 글자와 첫 글자가 다르면
			++OtherWordCount;
		}

		// 글자 수가 같으면
		if (FirstWordCount == OtherWordCount)
		{
			// 초기화
			++answer;
			FirstWord = ' ';
			FirstWordCount = 0;
			OtherWordCount = 0;
		}
	}

	// 나머지 문자
	// 문자가 분해되지 않음
	if (' ' != FirstWord)
	{
		++answer;
	}

	return answer;
}