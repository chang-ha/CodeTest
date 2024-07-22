#include <TimeCheck\TimeCheck.h>

using namespace std;

int solution(vector<int> numbers)
{
	int answer = 45; // sum of 0 ~ 9

	for (const int _CurValue : numbers)
	{
		answer -= _CurValue;
	}

	return answer;
}

int main()
{
	solution({1,2,3,4,6,7,8,0});
	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
		});

	int x = 0;
}