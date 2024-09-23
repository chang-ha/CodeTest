#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/42586

using namespace std;

// �ٸ���� Ǯ��
vector<int> Otherssolution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int day;
	int max_day = 0;
	const size_t progresses_size = progresses.size();
	for (int i = 0; i < progresses_size; ++i)
	{
		day = (99 - progresses[i]) / speeds[i] + 1;

		if (answer.empty() || max_day < day)
			answer.push_back(1);
		else
			++answer.back();

		if (max_day < day)
			max_day = day;
	}

	return answer;
}

// ��ǲ 30�� vector ����
// ���� �������� ���� üũ ���ϸ� �����
#include <algorithm>
vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	const size_t progresses_size = progresses.size();
	const size_t speeds_size = speeds.size();

	if (progresses_size != speeds_size)
	{
		// Error
		return { -1 };
	}

	vector<int> answer;

	for (size_t i = 0; i < progresses_size;)
	{
		int Develop_day = (99 - progresses[i]) / speeds[i] + 1;

		for (size_t j = i; j < progresses_size; j++)
		{
			progresses[j] += speeds[j] * Develop_day;
		}

		int Develop_Function = 0;
		while (i < progresses_size && 100 <= progresses[i])
		{
			++i;
			++Develop_Function;
		}

		answer.push_back(Develop_Function);
	}

	return answer;
}

