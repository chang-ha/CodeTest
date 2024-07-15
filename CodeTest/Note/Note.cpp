#include <TimeCheck\TimeCheck.h>


int main()
{
	int InputValue = 1000000000;
	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
			solution(InputValue);
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
			Othersolution(InputValue);
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
			listsolution(InputValue);
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
			dequesolution(InputValue);
		});

	int x = 0;
}