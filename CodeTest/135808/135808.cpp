#include <string>
#include <vector>

using namespace std;

#include <algorithm>
int ForVectorsolution(int k, int m, vector<int> score)
{
	if (0 == m)
	{
		return -1;
	}

	int answer = 0;
	// ������ ���� ������ sort
	std::sort(score.begin(), score.end(), std::greater<int>());
	size_t Score_Size = score.size();

	// �� ������ ���� ���� ���� �������� ���
	for (size_t i = m - 1; i < Score_Size; i += m)
	{
		answer += score[i] * m;
	}

	return answer;
}

#include <queue>
int PriorotyQueue_Vectorsolution(int k, int m, vector<int> score)
{
	int answer = 0;

	// �켱���� queue�� ������ ���� ������ ����
	std::priority_queue<int, vector<int>, less<int> > SortApple(score.begin(), score.end());

	while (m <= SortApple.size())
	{
		// ���� ���� ������ ����� ���ö� ���� pop
		for (int i = 0; i < m - 1; i++)
		{
			SortApple.pop();
		}
		// ���� ���� ������ ��� * m
		answer += SortApple.top() * m;
		SortApple.pop();
	}

	return answer;
}