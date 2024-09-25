#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/142085

using namespace std;

#include <queue>
int solution(int n, int k, vector<int> enemy)
{
	int answer = 0;

	std::priority_queue<int, std::vector<int>> enemy_queue;
	// deque -> �ڷ���� ����(enemy[i]) �߰��� ���� ���� �����ؼ� ������ �� ���Ҵµ�
	// ���� �������� vector�� 2~3�� ����... (�ڷ�� ���� ��� ����)
	// std::priority_queue<int, std::deque<int>> enemy_queue;
	for (const int Curenemy : enemy)
	{
		n -= Curenemy;
		enemy_queue.push(Curenemy);

		if (0 > n)
		{
			if (0 >= k)
			{
				break;
			}

			--k;
			n += enemy_queue.top();
			enemy_queue.pop();
		}
		++answer;
	}

	return answer;
}