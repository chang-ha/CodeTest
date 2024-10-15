#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/172927

using namespace std;

#include <stdexcept>
#include <algorithm>
#include <numeric>
int solution(vector<int> picks, vector<string> minerals)
{
	// ���� ����
	const int minerals_size = static_cast<int>(minerals.size());
	if (0 == minerals_size)
	{
		return 0;
	}

	// ��� ����
	const int picks_count = std::accumulate(picks.begin(), picks.end(), 0);
	if (0 == picks_count)
	{
		return 0;
	}

	// ��� ������ ���� �� ����
	const int minerals_vector_size = std::min(minerals_size / 5 + 1, picks_count);
	// Sum minerals Value , Sum minerals count
	std::vector<std::pair<int, int>> minerals_vector(minerals_vector_size, { 0, 0 });

	for (int i = 0, j = 0; i < minerals_size && j < picks_count; i++, j = i / 5)
	{
		int minerals_value = 0;
		
		if ("diamond" == minerals[i])
		{
			minerals_value = 25;
		}
		else if ("iron" == minerals[i])
		{
			minerals_value = 5;
		}
		else if ("stone" == minerals[i])
		{
			minerals_value = 1;
		}
		else
		{
			throw std::invalid_argument("argument contains not mineral's name");
		}

		// ������ Value�� ����
		minerals_vector[i / 5].first += minerals_value;
		// ������ ������ ����
		minerals_vector[i / 5].second += 1;
	}

	// ���� Value�� Sort
	std::sort(minerals_vector.begin(), minerals_vector.end(), [](const std::pair<int, int>& First, const std::pair<int, int>& Second)
		{
			return First.first > Second.first;
		});

	int answer = 0;

	for (int i = 0, Cur_pick = 0; i < minerals_vector_size; i++)
	{
		while (0 == picks[Cur_pick])
		{
			++Cur_pick;
		}

		switch (Cur_pick)
		{
		// ���̾� ���
		case 0:
			// �Ƿε� = ������ ����
			answer += minerals_vector[i].second;
			break;
		// ö ���
		case 1:
		{
			// Value�� 5�� ����� ������ ���
			// 1. ö 5�� or �� 5��
			// 2. ���̾� 1��
			// 3. ���̾Ʒθ� �̷�� ��
			if (5 == minerals_vector[i].first)
			{
				// 5 iron or 5 ston or 1 dia
				// �Ƿε� = ������ ����
				answer += minerals_vector[i].second;
			}
			else
			{
				// �Ƿε� = value / 5 + value % 5 (���̾� ĳ�µ� �Ƿε� 5 �Ҹ� + ������ ���� ĳ�µ� �Ƿε� 1 �Ҹ�)
				answer += minerals_vector[i].first / 5 + minerals_vector[i].first % 5;
			}
			break;
		}
		// �� ���
		case 2:
			// �Ƿε� = ������ Value
			answer += minerals_vector[i].first;
			break;
		default:
			throw std::invalid_argument("pick type invalid");
		}

		picks[Cur_pick] -= 1;
	}

	return answer;
}