#include <TimeCheck\TimeCheck.h>
#include <string>
#include <vector>

using namespace std;


int main()
{
	std::vector<int> InputVector = { 1,2,3,4,5 };
	int InputValue = 7;
	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
			Otherssolution(InputVector, InputValue);
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
			Bestsolution(InputVector, InputValue);
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
		});

	int x = 0;
}