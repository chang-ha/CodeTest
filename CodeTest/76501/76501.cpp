#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/76501

using namespace std;

#include <limits.h>
int solution(vector<int> absolutes, vector<bool> signs)
{
	int answer = 0;

	const size_t Integet_Number = absolutes.size();

	if (signs.size() != Integet_Number)
	{
		// Error
		return INT_MIN;
	}

	int MultiNum = 1;
	for (size_t i = 0; i < Integet_Number; i++)
	{
		switch (signs[i])
		{
		case true:
			MultiNum = 1;
			break;
		case false:
			MultiNum = -1;
			break;
		default:
			// Error
			return INT_MIN;
		}

		answer += absolutes[i] * MultiNum;
	}

	return answer;
}