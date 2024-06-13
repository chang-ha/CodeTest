#include <bits/stdc++.h>
using namespace std;

int commonChild(string s1, string s2)
{
	std::vector<std::vector<int>> Result;

	size_t s1_Size = s1.size();
	size_t s2_Size = s2.size();

	Result.resize(s1_Size + 1);
	for (std::vector<int>& CurVector : Result)
	{
		CurVector.resize(s2.size() + 1);
	}

	
	for (size_t i = 1; i < s1_Size + 1; i++)
	{
		for (size_t j = 1; j < s2_Size + 1; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				Result[i][j] = Result[i - 1][j - 1] + 1;
			}
			else
			{
				Result[i][j] = max(Result[i - 1][j], Result[i][j - 1]);
			}
		}
	}

	return Result[s1_Size][s1_Size];
}


int main()
{
	commonChild("LARRY", "SALLY");
}
