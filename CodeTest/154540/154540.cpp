#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/154540
using namespace std;

// Recursive없는 DFS로 해결
#include <stack>
#include <array>
#include <algorithm>
vector<int> solution(vector<string> maps)
{
	const int mapsColSize = static_cast<int>(maps.size());
	if (0 == mapsColSize)
	{
		return { -1 };
	}

	const int mapsRowSize = static_cast<int>(maps[0].size());
	if (0 == mapsRowSize)
	{
		return { -1 };
	}

	vector<int> answer;
	std::vector<std::vector<bool>> visitVector(mapsColSize, std::vector<bool>(mapsRowSize, false));
	std::stack<std::pair<int, int>> DfsStack;

	for (int i = 0; i < mapsColSize; i++)
	{
		for (int j = 0; j < mapsRowSize; j++)
		{
			if (true == visitVector[i][j] || 'X' == maps[i][j])
			{
				continue;
			}

			DfsStack.emplace(i, j);
			visitVector[i][j] = true;

			int landScale = maps[i][j] - '0';
			while (false == DfsStack.empty())
			{
				const int curY = DfsStack.top().first;
				const int curX = DfsStack.top().second;

				for (int Index = 0; Index < 4; Index++)
				{
					static std::array<const int, 4> directionX = { -1, 1, 0, 0 };
					static std::array<const int, 4> directionY = { 0, 0, -1, 1 };

					int calcuX = curX + directionX[Index];
					int calcuY = curY + directionY[Index];

					if (0 > calcuX || mapsRowSize <= calcuX ||
						0 > calcuY || mapsColSize <= calcuY)
					{
						continue;
					}

					if (true == visitVector[calcuY][calcuX] || 'X' == maps[calcuY][calcuX])
					{
						continue;
					}

					visitVector[calcuY][calcuX] = true;
					landScale += maps[calcuY][calcuX] - '0';
					DfsStack.emplace(calcuY, calcuX);
					break;
				}

				if (curY == DfsStack.top().first &&
					curX == DfsStack.top().second)
				{
					DfsStack.pop();
				}
			}
			answer.push_back(landScale);
		}
	}

	if (0 == answer.size())
	{
		answer.push_back(-1);
	}
	else
	{
		std::sort(answer.begin(), answer.end());
	}

	return answer;
}