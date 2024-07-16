#include <string>
#include <vector>

using namespace std;

string ForLoop_solution(int n)
{
	string answer = "";
	size_t Reserve_Value = static_cast<size_t>(n) * 4;
	answer.reserve(Reserve_Value);

	int LoopValue = n / 2;
	for (int i = 0; i < LoopValue; i++)
	{
		answer += "수박";
	}
	if (1 == n % 2)
	{
		answer += "수";
	}
	return answer;
}

string solution(int n)
{
	string answer = "";
	size_t Reserve_Value = static_cast<size_t>(n) * 4;
	answer.reserve(Reserve_Value);

	while (n >= 2)
	{
		answer += "수박";
		n -= 2;
	}

	if (0 != n)
	{
		answer += "수";
	}

	return answer;
}

string Mix_solution(int n)
{
	string answer = "";
	size_t Reserve_Value = static_cast<size_t>(n) * 4;
	answer.reserve(Reserve_Value);

	while (n >= 2)
	{
		answer += "수박";
		n -= 2;
	}

	answer.append("수박", n * 2);

	return answer;
}

string Append_solution(int n)
{
	string answer = "";
	size_t Reserve_Value = static_cast<size_t>(n) * 4;
	answer.reserve(Reserve_Value);

	while (n >= 2)
	{
		answer.append("수박");
		n -= 2;
	}

	answer.append("수박", n * 2);

	return answer;
}