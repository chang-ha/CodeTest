#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w)
{
	int answer = 0;
	int board_size = static_cast<int>(board.size());

	if (0 != board_size && board[0].size() != board_size)
	{
		// Error
		return -1;
	}

	if (0 > h || 0 > w ||
		board_size <= h || board_size <= w)
	{
		return -1;
	}

	std::string MyColor = board[h][w];

	if (h >= 1)
	{
		answer += MyColor == IsSameColor(board, h - 1, w) ? 1 : 0;
	}

	if (h < board_size)
	{
		answer += MyColor == IsSameColor(board, h + 1, w) ? 1 : 0;
	}

	if (w >= 1)
	{
		answer += MyColor == IsSameColor(board, h, w - 1) ? 1 : 0;
	}

	if (w < board_size)
	{
		answer += MyColor == IsSameColor(board, h, w + 1) ? 1 : 0;
	}

	return answer;
}

std::string IsSameColor(const std::vector<std::vector<std::string>>& board, const int X, const int Y)
{
	int board_size = static_cast<int>(board.size());

	if (0 > X || 0 > Y)
	{
		return "NULL";
	}

	if (board_size <= X || board_size <= Y)
	{
		return "NULL";
	}

	std::string Result = board[X][Y];

	return Result;
}

int Functionsolution(vector<vector<string>> board, int h, int w)
{
	int answer = 0;
	int board_size = static_cast<int>(board.size());

	if (0 != board_size && board[0].size() != board_size)
	{
		// Error
		return -1;
	}

	if (0 > h || 0 > w ||
		board_size <= h || board_size <= w)
	{
		return -1;
	}

	std::string MyColor = IsSameColor(board, h, w);
	answer += MyColor == IsSameColor(board, h - 1, w) ? 1 : 0;
	answer += MyColor == IsSameColor(board, h + 1, w) ? 1 : 0;
	answer += MyColor == IsSameColor(board, h, w - 1) ? 1 : 0;
	answer += MyColor == IsSameColor(board, h, w + 1) ? 1 : 0;

	return answer;
}

int atsolution(vector<vector<string>> board, int h, int w)
{
	int answer = 0;
	int board_size = static_cast<int>(board.size());

	if (0 != board_size && board[0].size() != board_size)
	{
		// Error
		return -1;
	}

	// out of range시 매우 느려짐
	std::string MyColor = "";
	try
	{
		MyColor = board.at(h).at(w);
	}
	catch (const std::out_of_range&)
	{
		// Error
		return -1;
	}

	try
	{
		answer += MyColor == board.at(h - 1).at(w) ? 1 : 0;
	}
	catch (const std::out_of_range&)
	{
	}

	try
	{
		answer += MyColor == board.at(h + 1).at(w) ? 1 : 0;
	}
	catch (const std::out_of_range&)
	{
	}

	try
	{
		answer += MyColor == board.at(h).at(w - 1) ? 1 : 0;
	}
	catch (const std::out_of_range&)
	{
	}

	try
	{
		answer += MyColor == board.at(h).at(w + 1) ? 1 : 0;
	}
	catch (const std::out_of_range&)
	{
	}

	return answer;
}
