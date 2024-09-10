#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/147354

using namespace std;

#include <algorithm>
int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
	const size_t data_size = data.size();
	if (0 == data_size)
	{
		return -1;
	}

	const size_t data_col_size = data[0].size();
	if (col > data_col_size || 0 >= col)
	{
		return -1;
	}

	if (0 >= row_begin)
	{
		return -1;
	}

	if (row_end > data_size)
	{
		return -1;
	}

	int answer = 0;

	std::sort(data.begin(), data.end(), [sortIndex = col - 1](const std::vector<int>& _First, const std::vector<int>& _Second)
		{
			return _First[sortIndex] == _Second[sortIndex] ? _First[0] > _Second[0] : _First[sortIndex] < _Second[sortIndex];
		});

	for (size_t i = row_begin; i <= row_end; i++)
	{
		int SumData = 0;
		for (const int CurValue : data[i - 1])
		{
			SumData += CurValue % i;
		}
		answer ^= SumData;
	}

	return answer;
}