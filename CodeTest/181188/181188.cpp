#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/181188

using namespace std;

#include <algorithm>

bool greaterVector(const std::vector<int>& _Vector1, const std::vector<int>& _Vector2)
{
	return _Vector1[1] < _Vector2[1];
}

int solution(vector<vector<int>> targets)
{
	int answer = 0;

	std::sort(targets.begin(), targets.end(), greaterVector);

	int LaunchPos = -1;
	for (const vector<int>& _CurTarget : targets)
	{
		if (_CurTarget[0] >= LaunchPos)
		{
			++answer;
			LaunchPos = _CurTarget[1];
		}
	}

	return answer;
}
