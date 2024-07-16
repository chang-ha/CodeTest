#include <TimeCheck\TimeCheck.h>


int main()
{
	std::vector<int> InputVector = { 1,10,20,50,70 };
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