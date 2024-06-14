#include <bits/stdc++.h>
using namespace std;

int minimumAbsoluteDifference(vector<int> arr)
{
	std::multiset<int> CalcuSet;

	for (int _CurInt : arr)
	{
		CalcuSet.insert(_CurInt);
	}

	std::multiset<int>::const_iterator FirstElement = CalcuSet.begin();
	std::multiset<int>::const_iterator SecondElement = CalcuSet.begin();
	std::advance(SecondElement, 1);
	std::multiset<int>::const_iterator EndElement = CalcuSet.end();
	int Result = INT_MAX;

	for (; SecondElement != EndElement;)
	{
		Result = std::min(Result, std::abs(*FirstElement - *SecondElement));
		++FirstElement;
		++SecondElement;
	}

	return Result;
}

int main()
{
	minimumAbsoluteDifference({1,-2,3,-4,5,-6});
}
