#include <string>
#include <vector>

// 문제 
// https://school.programmers.co.kr/learn/courses/30/lessons/159993

using namespace std;

#include <queue>
#include <array>
int BFSFindGoal(const std::pair<int, int> StartPos, const std::pair<int, int> GoalPos, const std::vector<std::string>& maps)
{
	const size_t maps_Col_size = maps.size();
	if (0 == maps_Col_size)
	{
		return -1;
	}

	const size_t maps_Row_size = maps[0].size();
	if (0 == maps_Row_size)
	{
		return -1;
	}

	if (0 > StartPos.second || maps_Col_size <= StartPos.first ||
		0 > StartPos.first || maps_Row_size <= StartPos.second)
	{
		// Error
		return -1;
	}

	if (0 > GoalPos.second || maps_Col_size <= GoalPos.first ||
		0 > GoalPos.first || maps_Row_size <= GoalPos.second)
	{
		// Error
		return -1;
	}

	std::vector<std::vector<int>> BFS_maps(maps_Col_size, std::vector<int>(maps_Row_size, 0));
	std::queue<std::pair<int, int>> BFS_queue;
	BFS_queue.push(StartPos);
	BFS_maps[StartPos.first][StartPos.second] = 1;

	static std::array<int, 4> Direction_X = { -1, 1, 0, 0 };
	static std::array<int, 4> Direction_Y = { 0, 0, -1, 1 };

	while (false == BFS_queue.empty())
	{
		const int CurY = BFS_queue.front().first;
		const int CurX = BFS_queue.front().second;
		BFS_queue.pop();

		for (size_t i = 0; i < 4; i++)
		{
			int CalcuX = CurX + Direction_X[i];
			int CalcuY = CurY + Direction_Y[i];

			if (0 > CalcuX || maps_Row_size <= CalcuX ||
				0 > CalcuY || maps_Col_size <= CalcuY)
			{
				// out of maps
				continue;
			}

			if ('X' == maps[CalcuY][CalcuX] || 0 < BFS_maps[CalcuY][CalcuX])
			{
				// wall or visited
				continue;
			}

			BFS_maps[CalcuY][CalcuX] = BFS_maps[CurY][CurX] + 1;
			BFS_queue.push(std::make_pair(CalcuY, CalcuX));
		}
	}

	return BFS_maps[GoalPos.first][GoalPos.second] - 1;
}

// BFS 2번 사용으로 해결 = Start -> Lever + Lever -> Goal
#include <stdexcept>
int solution(vector<string> maps)
{
	const size_t maps_Col_size = maps.size();
	if (0 == maps_Col_size)
	{
		return 0;
	}

	const size_t maps_Row_size = maps[0].size();
	if (0 == maps_Row_size)
	{
		return 0;
	}

	std::pair<int, int> StartPos = { -1, -1 };
	std::pair<int, int> LeverPos = { -1, -1 };
	std::pair<int, int> GoalPos = { -1, -1 };
	for (size_t i = 0; i < maps_Col_size; i++)
	{
		const size_t Find_Start_Pos1 = maps[i].find_first_of('S');
		const size_t Find_Start_Pos2 = maps[i].find_last_of('S');

		if (std::string::npos != Find_Start_Pos1)
		{
			if (Find_Start_Pos1 != Find_Start_Pos2 || -1 != StartPos.first)
			{
				throw std::invalid_argument("'S' exists More than two");
			}
			else
			{
				StartPos = { static_cast<int>(i), static_cast<int>(Find_Start_Pos1) };
			}
		}

		const size_t Find_Lever_Pos1 = maps[i].find_first_of('L');
		const size_t Find_Lever_Pos2 = maps[i].find_last_of('L');

		if (std::string::npos != Find_Lever_Pos1)
		{
			if (Find_Lever_Pos1 != Find_Lever_Pos2 || -1 != LeverPos.first)
			{
				throw std::invalid_argument("'L' exists More than two");
			}
			else
			{
				LeverPos = { static_cast<int>(i), static_cast<int>(Find_Lever_Pos1) };
			}
		}

		const size_t Find_Goal_Pos1 = maps[i].find_first_of('E');
		const size_t Find_Goal_Pos2 = maps[i].find_last_of('E');

		if (std::string::npos != Find_Goal_Pos1)
		{
			if (Find_Goal_Pos1 != Find_Goal_Pos2 || -1 != GoalPos.first)
			{
				throw std::invalid_argument("'G' exists More than two");
			}
			else
			{
				GoalPos = { static_cast<int>(i), static_cast<int>(Find_Goal_Pos1) };
			}
		}
	}

	int LeverDistance = BFSFindGoal(StartPos, LeverPos, maps);
	int GoalDistance = BFSFindGoal(LeverPos, GoalPos, maps);

	if (-1 == LeverDistance || -1 == GoalDistance)
	{
		return -1;
	}

	return LeverDistance + GoalDistance;
}