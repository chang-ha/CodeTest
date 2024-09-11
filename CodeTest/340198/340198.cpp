#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/340198

using namespace std;

#include <algorithm>
int solution(vector<int> mats, vector<vector<string>> park)
{
	int answer = -1;
	std::sort(mats.begin(), mats.end(), greater<int>());

	const size_t Col_park_size = park.size();

	if (0 == Col_park_size)
	{
		// Error
		return answer;
	}

	const size_t Row_park_size = park[0].size();

	if (0 == Row_park_size)
	{
		// Error
		return answer;
	}

	for (size_t i = 0; i < Col_park_size; i++)
	{
		for (size_t j = 0; j < Row_park_size; j++)
		{
			if ("-1" == park[i][j])
			{

			}
		}
	}

	return answer;
}