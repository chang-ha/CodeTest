#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/49993

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;

	std::vector<int> PrevSkill('Z' - 'A' + 1, 0);

	const int skill_size = static_cast<int>(skill.size());
	for (int i = 0; i < skill_size; i++)
	{
		PrevSkill[skill[i] - 'A'] = i + 1;
	}

	for (const std::string& CurSkill : skill_trees)
	{
		++answer;
		const int CurSkill_size = static_cast<int>(CurSkill.size());
		for (int i = 0, Order = 1; i < CurSkill_size; i++)
		{
			int Value = PrevSkill[CurSkill[i] - 'A'];
			if (0 == Value)
			{
				continue;
			}

			if (Order != Value)
			{
				--answer;
				break;
			}
			++Order;
		}
	}

	return answer;
}