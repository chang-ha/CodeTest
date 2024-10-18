#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/72413

using namespace std;

// Dijkstra 풀이
#include <stdexcept>
#include <queue>
int Dijkstrasolution(int n, int s, int a, int b, vector<vector<int>> fares)
{
	constexpr int MaxValue = 100000;

	std::vector<std::vector<int>> DijkstraVector(n + 1, std::vector<int>(n + 1, MaxValue));
	for (size_t i = 1; i <= n; i++)
	{
		DijkstraVector[i][i] = 0;
	}

	for (const std::vector<int>& CurFare : fares)
	{
		if (3 != CurFare.size())
		{
			throw std::invalid_argument("fare's size must be 3");
		}

		DijkstraVector[CurFare[0]][CurFare[1]] = CurFare[2];
		DijkstraVector[CurFare[1]][CurFare[0]] = CurFare[2];
	}

	// 내부에서 힙 구조 (log N)
	std::priority_queue<int, std::vector<int>, std::greater<int>> DijkstraQueue;

	// 4
	DijkstraQueue.push(s);

	while (false == DijkstraQueue.empty())
	{
		int StartIndex = DijkstraQueue.top();
		DijkstraQueue.pop();
	}

	int answer = MaxValue;
	return answer;
}