#include <string>
#include <vector>

using namespace std;

#include <queue>
int PriorotyQueue_Vectorsolution(int k, int m, vector<int> score)
{
	int answer = 0;

	std::priority_queue<int, vector<int>, less<int> > SortApple(score.begin(), score.end());

	while (m <= SortApple.size())
	{
		for (int i = 0; i < m - 1; i++)
		{
			SortApple.pop();
		}
		answer += SortApple.top() * m;
		SortApple.pop();
	}

	return answer;
}

int Dequesolution(int k, int m, vector<int> score)
{
	int answer = 0;

	std::priority_queue<int, deque<int>, less<int> > SortApple(score.begin(), score.end());

	return answer;
}

int ForVectorsolution(int k, int m, vector<int> score)
{
	int answer = 0;

	std::priority_queue<int, vector<int>, less<int> > SortApple;

	for (const int _CurScore : score)
	{
		SortApple.push(_CurScore);
	}

	return answer;
}
