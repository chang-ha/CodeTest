#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
	vector<int> answer = arr;

	for (const std::vector<int>& _CurQuery : queries)
	{
		for (int i = _CurQuery[0]; i <= _CurQuery[1]; i++)
		{
			if (0 == i % _CurQuery[2])
			{
				answer[i] += 1;
			}
		}
	}

	return answer;

}