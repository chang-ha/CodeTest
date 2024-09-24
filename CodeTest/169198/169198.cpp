#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/169198

using namespace std;

// YÃà, XÃà ´ëÄªÀ¸·Î ÇØ°á
#include <limits.h>
#include <algorithm>
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
	vector<int> answer;
	answer.reserve(balls.size());

	for (const std::vector<int>& Curball : balls)
	{
		if (2 != Curball.size())
		{
			// Error
			return { -1 };
		}

		std::vector<int> CalcuDistance;
		CalcuDistance.reserve(4);
		// X = 0 ´ëÄª
		if (startY != Curball[1] || startX < Curball[0])
		{
			int symmetry_X = -Curball[0];
			int Distance_X = startX - symmetry_X;
			int Distance_Y = startY - Curball[1];
			CalcuDistance.push_back(Distance_X * Distance_X + Distance_Y * Distance_Y);
		}
		// X = m ´ëÄª
		if (startY != Curball[1] || startX > Curball[0])
		{
			int symmetry_X = m + (m - Curball[0]);
			int Distance_X = startX - symmetry_X;
			int Distance_Y = startY - Curball[1];
			CalcuDistance.push_back(Distance_X * Distance_X + Distance_Y * Distance_Y);
		}
		// Y = 0 ´ëÄª
		if (startX != Curball[0] || startY < Curball[1])
		{
			int symmetry_Y = -Curball[1];
			int Distance_X = startX - Curball[0];
			int Distance_Y = startY - symmetry_Y;
			CalcuDistance.push_back(Distance_X * Distance_X + Distance_Y * Distance_Y);
		}
		// Y = n ´ëÄª
		if (startX != Curball[0] || startY > Curball[1])
		{
			int symmetry_Y = n + (n - Curball[1]);
			int Distance_X = startX - Curball[0];
			int Distance_Y = startY - symmetry_Y;
			CalcuDistance.push_back(Distance_X * Distance_X + Distance_Y * Distance_Y);
		}

		answer.push_back(*std::min_element(CalcuDistance.begin(), CalcuDistance.end()));
	}

	return answer;
}