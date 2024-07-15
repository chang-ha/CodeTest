#include <TimeCheck\TimeCheck.h>

#include <string>
#include <vector>

using namespace std;

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

string solution2(int n) {
	string answer = "";

	for (int i = 0; i < n; i++)
		i & 1 ? answer += "박" : answer += "수";

	return answer;
}

string solution3(int n)
{
	string answer = "";
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


int main()
{
	int InputValue = 101;
	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
			solution(InputValue);
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
			solution2(InputValue);
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
			solution3(InputValue);
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
		});

	int x = 0;
}