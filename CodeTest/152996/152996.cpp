#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/152996

using namespace std;

// Counting Sort 방식이 4~5배 정도 빠름
long long Vectorsolution(vector<int> weights)
{
	long long answer = 0;

	// 무게 범위 100 ~ 1000
	vector<long long> CountingSort(1001, 0);

	for (const int Curweight : weights)
	{
		CountingSort[Curweight] += 1;
	}

	for (int i = 100; i <= 1000; i++)
	{
		if (0 == CountingSort[i])
		{
			continue;
		}

		// 2 : 4 == 4 : 2
		int FindWeight = i * 2;
		if (1000 >= FindWeight)
		{
			answer += CountingSort[i] * CountingSort[FindWeight];
		}

		// 2 : 3 == 3 : 2
		if (0 == i % 2)
		{
			FindWeight = i / 2 * 3;
			if (1000 >= FindWeight)
			{
				answer += CountingSort[i] * CountingSort[FindWeight];
			}
		}

		// 3 : 4 == 4 : 3
		if (0 == i % 3)
		{
			FindWeight = i / 3 * 4;
			if (1000 >= FindWeight)
			{
				answer += CountingSort[i] * CountingSort[FindWeight];
			}
		}

		// 2 : 2 == 3 : 3 == 4 : 4
		answer += (CountingSort[i] - 1) * CountingSort[i] / 2;
	}

	return answer;
}

#include <unordered_map>
long long Mapsolution(vector<int> weights)
{
	long long answer = 0;
	// 무게 - 몇 명 매핑
	std::unordered_map<int, long long> weight_map;
	for (const int Curweight : weights)
	{
		weight_map[Curweight] += 1;
	}

	for (const std::pair<int, long long>& Curpair : weight_map)
	{
		// 2 : 4 == 4 : 2
		int FindWeight = Curpair.first * 2;
		std::unordered_map<int, long long>::const_iterator FindIter = weight_map.find(FindWeight);
		if (weight_map.end() != FindIter)
		{
			answer += FindIter->second * Curpair.second;
		}

		// 2 : 3 == 3 : 2
		if (0 == Curpair.first % 2)
		{
			FindWeight = Curpair.first / 2 * 3;
			FindIter = weight_map.find(FindWeight);
			if (weight_map.end() != FindIter)
			{
				answer += FindIter->second * Curpair.second;
			}
		}

		// 3 : 4 == 4 : 3
		if (0 == Curpair.first % 3)
		{
			FindWeight = Curpair.first / 3 * 4;
			FindIter = weight_map.find(FindWeight);
			if (weight_map.end() != FindIter)
			{
				answer += FindIter->second * Curpair.second;
			}
		}

		// 2 : 2 == 3 : 3 == 4 : 4
		if (2 > Curpair.second)
		{
			continue;
		}
		answer += (Curpair.second - 1) * Curpair.second / 2;
	}

	return answer;
}