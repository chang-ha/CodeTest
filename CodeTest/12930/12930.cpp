#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
	string answer = s;

	for (int i = 0, WordCount = 0; answer[i] != 0; i++, WordCount++)
	{
		if (' ' == answer[i])
		{
			WordCount = -1;
			continue;
		}

		if (0 == WordCount % 2)
		{
			answer[i] = std::toupper(answer[i]);
		}
		else
		{
			answer[i] = std::tolower(answer[i]);
		}
	}

	return answer;
}

#include <sstream>
string SStreamSolution(string s)
{
	std::stringstream CalcuString(s);

	std::string answer = "";
	std::string Word = "";
	while (CalcuString >> Word)
	{
		if ("" != answer)
		{
			answer += " ";
		}

		size_t Word_size = Word.size();
		for (size_t i = 0; i < Word_size; i++)
		{
			if (0 == (i & 1))
			{
				Word[i] = std::toupper(Word[i]);
			}
			else
			{
				Word[i] = std::tolower(Word[i]);
			}
		}

		answer += Word;
	}
	return answer;
}