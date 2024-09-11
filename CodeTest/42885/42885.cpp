#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/42885

using namespace std;

#include <algorithm>
int solution(vector<int> people, int limit)
{
	int answer = 0;

	std::sort(people.begin(), people.end());

	int Minimum = 0;
	int Maximum = static_cast<int>(people.size()) - 1;

	while (Minimum <= Maximum)
	{
		if (limit >= people[Maximum] + people[Minimum])
		{
			++Minimum;
		}
		--Maximum;
		++answer;
	}

	return answer;
}
