#include <TimeCheck\TimeCheck.h>


int main()
{
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