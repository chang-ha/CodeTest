#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/142085

using namespace std;

#include <queue>
int solution(int n, int k, vector<int> enemy)
{
	int answer = 0;

	std::priority_queue<int, std::vector<int>> enemy_queue;
	// deque -> 자료양이 많고(enemy[i]) 중간에 값을 삽입 삭제해서 유리할 것 같았는데
	// 실제 돌려보면 vector가 2~3배 빠름... (자료양 많은 경우 포함)
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