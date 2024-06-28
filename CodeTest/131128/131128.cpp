#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y)
{
	string answer = "";

	std::vector<int> X_Vector(10);
	for (const char _CurChar : X)
	{
		X_Vector[_CurChar - '0'] += 1;
	}

	std::vector<int> Y_Vector(10);
	for (const char _CurChar : Y)
	{
		Y_Vector[_CurChar - '0'] += 1;
	}

	for (int i = 9; i >= 0; i--)
	{
		answer.append(std::min(X_Vector[i], Y_Vector[i]), '0' + i);
	}

	if ("" == answer)
	{
		answer = "-1";
	}

	if (answer.begin() != answer.end() &&
		'0' == *answer.begin())
	{
		answer = "0";
	}

	return answer;
}