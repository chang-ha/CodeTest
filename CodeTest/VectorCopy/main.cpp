#include <vector>

#include <TimeCheck\TimeCheck.h>

using namespace std;

void CopyFunction(vector<int> _CopyVector)
{
	std::vector<int> Temp(_CopyVector.size());
	std::copy(_CopyVector.begin(), _CopyVector.end(), Temp.begin());
}

void StructureFunction(vector<int> _CopyVector)
{
	std::vector<int> Temp(_CopyVector.begin(), _CopyVector.end());
}

void ForFunction(vector<int> _CopyVector)
{
	std::vector<int> Temp;
	Temp.reserve(10000);

	for (size_t i = 0; i < 10000; i++)
	{
		Temp.push_back(_CopyVector[i]);
	}
}

#include <numeric>
int main()
{
	std::vector<int> AVector(10000);
	std::iota(AVector.begin(), AVector.end(), 0);

	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
			ForFunction(AVector);
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
			StructureFunction(AVector);
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
			CopyFunction(AVector);
		});

	int a = 0;
}
