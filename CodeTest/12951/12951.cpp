#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12951
using namespace std;

#include <algorithm>
string solution(string s)
{
	string answer;
	answer.resize(s.size());

	std::transform(s.begin(), s.end(), answer.begin(), ::tolower);

	size_t PrevPos = 0;
	size_t BlankPos = 0;
	while (std::string::npos != BlankPos)
	{
		BlankPos = answer.find(' ', PrevPos);
		char Word_FirstChar = answer[PrevPos];
		if (0 != std::isalpha(Word_FirstChar))
		{
			answer[PrevPos] = std::toupper(Word_FirstChar);
		}
		PrevPos = BlankPos + 1;
	}

	return answer;
}
