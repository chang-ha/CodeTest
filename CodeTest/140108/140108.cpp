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
		// ù ��° ����
		if (' ' == FirstWord)
		{
			FirstWord = _CurChar;
		}

		// ���� ���ڿ� ù ���� ������
		if (_CurChar == FirstWord)
		{
			++FirstWordCount;
		}
		else
		{
			// ���� ���ڿ� ù ���ڰ� �ٸ���
			++OtherWordCount;
		}

		// ���� ���� ������
		if (FirstWordCount == OtherWordCount)
		{
			// �ʱ�ȭ
			++answer;
			FirstWord = ' ';
			FirstWordCount = 0;
			OtherWordCount = 0;
		}
	}

	// ������ ����
	// ���ڰ� ���ص��� ����
	if (' ' != FirstWord)
	{
		++answer;
	}

	return answer;
}