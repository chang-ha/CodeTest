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
	// 점수가 높은 순으로 sort
	std::sort(score.begin(), score.end(), std::greater<int>());
	size_t Score_Size = score.size();

	// 한 상자의 가장 낮은 점수 기준으로 계산
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

	// 우선순위 queue에 점수가 높은 순으로 삽입
	std::priority_queue<int, vector<int>, less<int> > SortApple(score.begin(), score.end());

	while (m <= SortApple.size())
	{
		// 가장 낮은 점수의 사과가 나올때 까지 pop
		for (int i = 0; i < m - 1; i++)
		{
			SortApple.pop();
		}
		// 가장 낮은 점수의 사과 * m
		answer += SortApple.top() * m;
		SortApple.pop();
	}

	return answer;
}