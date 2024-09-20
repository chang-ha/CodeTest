#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12949

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
	const size_t arr1_size = arr1.size();
	const size_t arr2_size = arr2.size();
	vector<vector<int>> answer(arr1_size, std::vector<int>(arr2[0].size(), 0));

	if (0 == arr1_size || 0 == arr2_size)
	{
		return { {-1} };
	}

	const size_t arr2_row_size = arr2[0].size();

	if (arr1[0].size() != arr2_size)
	{
		return { {-1} };
	}

	for (size_t i = 0; i < arr1_size; i++)
	{
		for (size_t j = 0; j < arr2_size; j++)
		{
			for (size_t w = 0; w < arr2_row_size; w++)
			{
				answer[i][w] += arr1[i][j] * arr2[j][w];
			}
		}
	}

	return answer;
}