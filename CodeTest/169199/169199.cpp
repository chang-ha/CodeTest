#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/169199?language=cpp

using namespace std;

#include <queue>
#include <stdexcept>
#include <array>
int solution(vector<string> board)
{
	const size_t board_Col_size = board.size();
	if (0 == board_Col_size)
	{
		return -1;
	}

	const size_t board_Row_size = board[0].size();
	if (0 == board_Row_size)
	{
		return -1;
	}

	std::vector<std::vector<int>> board_vector(board_Col_size, std::vector<int>(board_Row_size, 0));

	// 시작위치와 목표 찾는 전처리
	std::pair<int, int> Goal = { -1, -1 };
	std::pair<int, int> Start = { -1, -1 };
	for (size_t i = 0; i < board_Col_size; i++)
	{
		const size_t Find_Start_Pos = board[i].find_first_of('R');
		const size_t Find_Start_Pos2 = board[i].find_last_of('R');

		if (std::string::npos != Find_Start_Pos)
		{
			if (Find_Start_Pos != Find_Start_Pos2 || -1 != Start.first)
			{
				throw std::invalid_argument("'R' exists More than two");
			}
			else
			{
				Start = { static_cast<int>(i), static_cast<int>(Find_Start_Pos) };
				board_vector[Start.first][Start.second] = 1;
			}
		}

		const size_t Find_Goal_Pos = board[i].find_first_of('G');
		const size_t Find_Goal_Pos2 = board[i].find_first_of('G');

		if (std::string::npos != Find_Goal_Pos)
		{
			if (Find_Start_Pos != Find_Start_Pos2 || -1 != Goal.first)
			{
				throw std::invalid_argument("'G' exists More than two");
			}
			else
			{
				Goal = { static_cast<int>(i), static_cast<int>(Find_Goal_Pos) };
			}
		}
	}

	std::queue<std::pair<int, int>> BFS_queue;
	BFS_queue.push(Start);

	while (!BFS_queue.empty())
	{
		const int CurY = BFS_queue.front().first;
		const int CurX = BFS_queue.front().second;
		BFS_queue.pop();

		for (size_t i = 0; i < 4; i++)
		{
			static std::array<int, 4> Direction_X = { -1, 1, 0, 0 };
			static std::array<int, 4> Direction_Y = { 0, 0, -1, 1 };

			int MoveCurX = CurX;
			int MoveCurY = CurY;

			while (true)
			{
				MoveCurX += Direction_X[i];
				MoveCurY += Direction_Y[i];

				if (0 > MoveCurX || board_Row_size <= MoveCurX ||
					0 > MoveCurY || board_Col_size <= MoveCurY ||
					'D' == board[MoveCurY][MoveCurX])
				{
					break;
				}
			}

			MoveCurX -= Direction_X[i];
			MoveCurY -= Direction_Y[i];
			if (0 == board_vector[MoveCurY][MoveCurX])
			{
				board_vector[MoveCurY][MoveCurX] = board_vector[CurY][CurX] + 1;
				BFS_queue.push({ MoveCurY, MoveCurX });
			}
		}
	}

	return board_vector[Goal.first][Goal.second] - 1;
}