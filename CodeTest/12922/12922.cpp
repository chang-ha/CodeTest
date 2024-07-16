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
		answer += "����";
	}
	if (1 == n % 2)
	{
		answer += "��";
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
		answer += "����";
		n -= 2;
	}

	if (0 != n)
	{
		answer += "��";
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
		answer += "����";
		n -= 2;
	}

	answer.append("����", n * 2);

	return answer;
}

string Append_solution(int n)
{
	string answer = "";
	size_t Reserve_Value = static_cast<size_t>(n) * 4;
	answer.reserve(Reserve_Value);

	while (n >= 2)
	{
		answer.append("����");
		n -= 2;
	}

	answer.append("����", n * 2);

	return answer;
}