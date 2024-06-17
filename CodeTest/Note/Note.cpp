#include <bits/stdc++.h>
using namespace std;

int luckBalance(int k, vector<vector<int>> contests)
{
	int Result = 0;
	std::multiset<int, std::greater<int>> LuckContainer;

	for (vector<int> CurLuck : contests)
	{
		if (2 != CurLuck.size())
		{
			// Error
			return INT_MIN;
		}

		if (0 == CurLuck[1])
		{
			Result += CurLuck[0];
		}
		else
		{
			LuckContainer.insert(CurLuck[0]);
		}
	}

	for (int CurLuck : LuckContainer)
	{
		if (0 < k)
		{
			--k;
			Result += CurLuck;
		}
		else
		{
			Result -= CurLuck;
		}
	}

	return Result;
}

int main()
{
	luckBalance(3, { {5,1}, {2,1}, {1,1}, {8,1}, {10,0}, {5,0} });
}
