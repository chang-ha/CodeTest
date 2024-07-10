#include <TimeCheck\TimeCheck.h>

#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2)
{
	return num1 * num2;
}

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

	int a = 0;
}