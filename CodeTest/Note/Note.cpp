#include <TimeCheck\TimeCheck.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
		});

	int a = 0;
}