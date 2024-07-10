#include <string>
#include <vector>

using namespace std;

#include <limits.h>
vector<int> ForLoopsolution(vector<int> arr, vector<vector<int>> queries)
{
	size_t Queries_Size = queries.size();
	vector<int> answer(Queries_Size, -1);

	for (size_t i = 0; i < Queries_Size; ++i)
	{
		int MinValue = INT_MAX;
		for (int j = queries[i][0]; j <= queries[i][1]; j++)
		{
			if (queries[i][2] >= arr[j])
			{
				continue;
			}

			MinValue = std::min(MinValue, arr[j]);
		}

		if (INT_MAX == MinValue)
		{
			continue;
		}

		answer[i] = MinValue;
	}

	return answer;
}

#include <algorithm>
vector<int> VectorCopysolution(vector<int> arr, vector<vector<int>> queries)
{
	vector<int> answer;

	for (const std::vector<int>& _CurQuery : queries)
	{
		std::vector<int> RangeVector(_CurQuery[1] - _CurQuery[0] + 1);
		std::copy(arr.begin() + _CurQuery[0], arr.begin() + _CurQuery[1] + 1, RangeVector.begin());
		std::sort(RangeVector.begin(), RangeVector.end());

		size_t Vector_Size = RangeVector.size();
		for (size_t i = 0; i < Vector_Size; i++)
		{
			if (RangeVector[i] > _CurQuery[2])
			{
				answer.push_back(RangeVector[i]);
				break;
			}

			if (i == Vector_Size - 1)
			{
				answer.push_back(-1);
			}
		}
	}
	return answer;
}