#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/340213

using namespace std;

// Time string to int
int CalcuTime(const std::string& _Time)
{
	if (5 != _Time.size())
	{
		return -1;
	}

	const size_t DividePos = _Time.find(':');

	const int Minute = std::stoi(_Time.substr(0, DividePos));
	const int Second = std::stoi(_Time.substr(DividePos + 1));

	return Minute * 60 + Second;
}

// Time int to string
std::string CalcuTime(const int _Time)
{
	const int Minute = _Time / 60;
	const int Second = _Time % 60;

	if (60 <= Minute)
	{
		return "59:59";
	}

	int Minute_Digit = 0 == Minute / 10 ? 1 : 0;
	int Second_Digit = 0 == Second / 10 ? 1 : 0;

	std::string Result = "00:00";
	Result.replace(Result.begin() + Minute_Digit, Result.begin() + 2, std::to_string(Minute));
	Result.replace(Result.end() - 2 + Second_Digit, Result.end(), std::to_string(Second));
	return Result;
}

#include <array>
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
	const int VideoLimit = CalcuTime(video_len);
	const int op_Start = CalcuTime(op_start);
	const int op_End = CalcuTime(op_end);
	int Pos = CalcuTime(pos);

	if (op_Start <= Pos && Pos <= op_End)
	{
		Pos = op_End;
	}

	for (const std::string& CurCommand : commands)
	{
		if ("next" == CurCommand)
		{
			Pos += 10;
		}
		else if ("prev" == CurCommand)
		{
			Pos -= 10;
		}
		else
		{
			return "Wrong Command";
		}

		if (0 > Pos)
		{
			Pos = 0;
		}
		else if (VideoLimit < Pos)
		{
			Pos = VideoLimit;
		}

		if (op_Start <= Pos && Pos <= op_End)
		{
			Pos = op_End;
		}
	}

	return CalcuTime(Pos);
}