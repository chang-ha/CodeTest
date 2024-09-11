#include<vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/1844

using namespace std;

// 너비 우선 탐색
// 같은 너비 우선해서 탐색
#include <queue>
#include <array>
int solution(vector<vector<int> > maps)
{
	const int Col_maps_size = static_cast<int>(maps.size());
	if (0 == Col_maps_size)
	{
		return -1;
	}

	const int Row_maps_size = static_cast<int>(maps[0].size());
	if (0 == Row_maps_size)
	{
		return -1;
	}

	std::vector<std::vector<int>> VisitMaps(Col_maps_size, vector<int>(Row_maps_size, 0));

	std::queue<std::pair<int, int>> MapOrder;
	MapOrder.push(std::make_pair(0, 0));
	VisitMaps[0][0] = 1;
	VisitMaps[Col_maps_size - 1][Row_maps_size - 1] = -1;

	while (false == MapOrder.empty())
	{
		const int CurY = MapOrder.front().first;
		const int CurX = MapOrder.front().second;
		MapOrder.pop();

		for (int i = 0; i < 4; i++)
		{
			static std::array<int, 4> Direction_X = { -1, 1, 0, 0 };
			static std::array<int, 4> Direction_Y = { 0, 0, -1, 1 };

			int MoveCurX = CurX + Direction_X[i];
			int MoveCurY = CurY + Direction_Y[i];

			if (0 > MoveCurX || Row_maps_size <= MoveCurX ||
				0 > MoveCurY || Col_maps_size <= MoveCurY)
			{
				continue;
			}

			if (0 == maps[MoveCurY][MoveCurX] || 0 < VisitMaps[MoveCurY][MoveCurX])
			{
				continue;
			}

			VisitMaps[MoveCurY][MoveCurX] = VisitMaps[CurY][CurX] + 1;
			MapOrder.push(std::make_pair(MoveCurY, MoveCurX));
		}
	}

	return VisitMaps[Col_maps_size - 1][Row_maps_size - 1];
}