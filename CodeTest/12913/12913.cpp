#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12913

using namespace std;

#include <stdexcept>
int solution(vector<vector<int> > land)
{
	const size_t land_size = land.size();
	if (0 == land_size)
	{
		return 0;
	}
	std::vector<std::vector<int>> ScoreVector(land_size, std::vector<int>(land[0].size(), 0));
	ScoreVector[0] = land[0];

	for (size_t i = 0; i < land_size - 1; i++)
	{
		const size_t landcol_size = land[i].size();
		if (4 != landcol_size)
		{
			throw std::invalid_argument("land_col size must be 4");
		}


		for (size_t CurIndex = 0; CurIndex < landcol_size; CurIndex++)
		{
			for (size_t PrevIndex = 0; PrevIndex < landcol_size; PrevIndex++)
			{
				if (PrevIndex == CurIndex)
				{
					continue;
				}

				ScoreVector[i + 1][CurIndex] = std::max(ScoreVector[i + 1][CurIndex], ScoreVector[i][PrevIndex] + land[i][CurIndex]);
			}
		}
	}

	int answer = 0;
	for (const int CurValue : ScoreVector[land_size - 1])
	{
		answer = std::max(answer, CurValue);
	}

	return answer;
}