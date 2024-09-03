#include <string>
#include <vector>

using namespace std;

#include <algorithm>
vector<int> solution(vector<int> arr, int divisor)
{
	vector<int> answer;
	answer.reserve(arr.size());

	for (const int _CurValue : arr)
	{
		if (0 == _CurValue % divisor)
		{
			answer.push_back(_CurValue);
		}
	}

	if (0 == answer.size())
	{
		answer.push_back(-1);
	}
	else
	{
	std:sort(answer.begin(), answer.end());
	}

	return answer;
}