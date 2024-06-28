#include <TimeCheck\TimeCheck.h>

using namespace std;
#include <vector>

#include <set>
int CreateSet(std::vector<int> _FindVector)
{
	std::set<int> Set(_FindVector.begin(), _FindVector.end());

	int MaxValue = *Set.rbegin();
	return MaxValue;
}

#include <algorithm>
int Use_MaxElement(std::vector<int> _FindVector)
{
	return *std::max_element(_FindVector.begin(), _FindVector.end());
}

int ForLoop_Max(std::vector<int> _FindVector)
{
	int MaxValue = INT_MIN;
	for (const int _CurValue : _FindVector)
	{
		MaxValue = std::max(MaxValue, _CurValue);
	}

	return MaxValue;
}

int ForLoop_Simple(std::vector<int> _FindVector)
{
	int MaxValue = INT_MIN;
	for (const int _CurValue : _FindVector)
	{
		if (_CurValue > MaxValue)
		{
			MaxValue = _CurValue;
		}
	}

	return MaxValue;
}

#include <numeric>
int main()
{
	std::vector<int> InputVector(10000);

	std::iota(InputVector.begin(), InputVector.end(), 1);

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
			ForLoop_Simple(InputVector);
		});

	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
			CreateSet(InputVector);
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
			Use_MaxElement(InputVector);
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
			ForLoop_Max(InputVector);
		});



	int a = 0;
}
