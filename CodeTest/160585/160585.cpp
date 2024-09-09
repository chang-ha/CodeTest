#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/160585

using namespace std;

int solution(vector<string> board)
{
	int answer = 1;

	const int board_size = static_cast<int>(board.size());

	if (3 != board_size)
	{
		return -1;
	}

	if (3 != board[0].size())
	{
		return -1;
	}

	std::vector<std::vector<char>> boardVector(3, std::vector<char>(3, ' '));

	int OCount = 0;
	int XCount = 0;

	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			const char CurValue = board[i][j];
			if ('O' == CurValue)
			{
				++OCount;
			}
			else if ('X' == CurValue)
			{
				++XCount;
			}

			boardVector[i][j] = board[i][j];
		}
	}

	const int DiffCount = OCount - XCount;
	if (1 < DiffCount || 0 > DiffCount)
	{
		return 0;
	}

	int XWinCase = 0;
	int OWinCase = 0;

	for (int i = 0; i < board_size; i++)
	{
		if ('O' == boardVector[i][0] && 'O' == boardVector[i][1] && 'O' == boardVector[i][2])
		{
			++OWinCase;
		}
		else if ('X' == boardVector[i][0] && 'X' == boardVector[i][1] && 'X' == boardVector[i][2])
		{
			++XWinCase;
		}

		if ('O' == boardVector[0][i] && 'O' == boardVector[1][i] && 'O' == boardVector[2][i])
		{
			++OWinCase;
		}
		else if ('X' == boardVector[0][i] && 'X' == boardVector[1][i] && 'X' == boardVector[2][i])
		{
			++XWinCase;
		}
	}

	const char CenterChar = boardVector[1][1];
	if ('O' == CenterChar)
	{
		if ('O' == boardVector[0][0] && 'O' == boardVector[2][2])
		{
			++OWinCase;
		}

		if ('O' == boardVector[0][2] && 'O' == boardVector[2][0])
		{
			++OWinCase;
		}
	}
	else if ('X' == CenterChar)
	{
		if ('X' == boardVector[0][0] && 'X' == boardVector[2][2])
		{
			++XWinCase;
		}

		if ('X' == boardVector[0][2] && 'X' == boardVector[2][0])
		{
			++XWinCase;
		}
	}

	if (1 == XWinCase && 1 == OWinCase)
	{
		return 0;
	}

	if (1 == OWinCase && 0 == DiffCount)
	{
		return 0;
	}

	if (1 == XWinCase && 1 == DiffCount)
	{
		return 0;
	}

	return 1;
}
