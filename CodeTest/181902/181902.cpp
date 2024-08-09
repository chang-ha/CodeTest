#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string)
{
	vector<int> answer(52, 0);

	for (const char _CurChar : my_string)
	{
		if (0 == std::isalpha(_CurChar))
		{
			// Error
			continue;
		}

		if (0 != std::isupper(_CurChar))
		{
			answer[_CurChar - 'A'] += 1;
		}
		else
		{
			answer[_CurChar - 'a' + 26] += 1;
		}
	}

	return answer;
}