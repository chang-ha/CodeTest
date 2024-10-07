#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/42842

using namespace std;

// 테두리 = 1줄
// 전체 가로 X = width_yellow + 2
// 전체 세로 Y = height_yellow + 2
// X * Y = brown + yellow
// (X - 2) * (Y - 2) = yellow
// 2X + 2Y = brown + 4
// (X - Y) ^ 2 = (X + Y)^2 - 4XY

#include <cmath>
vector<int> solution(int brown, int yellow)
{
	int SumXY = (brown + 4) / 2;
	int XY = brown + yellow;
	int DifXY = static_cast<int>(std::sqrt(SumXY * SumXY - 4 * XY));
	return { (SumXY + DifXY) / 2, (SumXY - DifXY) / 2 };
}