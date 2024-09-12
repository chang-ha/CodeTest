#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/340198

using namespace std;

#include <algorithm>
#include <unordered_set>
int solution(vector<int> mats, vector<vector<string>> park)
{
	int answer = -1;
	// 돗자리 큰 순으로 정렬
	std::sort(mats.begin(), mats.end(), greater<int>());

	const size_t Col_park_size = park.size();

	if (0 == Col_park_size)
	{
		// Error
		return answer;
	}

	const size_t Row_park_size = park[0].size();

	if (0 == Row_park_size)
	{
		// Error
		return answer;
	}

	// 가능한 돗자리 크기 set에 저장
	std::unordered_set<int> MatSet;

	// 가능한 돗자리 계산용 vector
	std::vector<std::vector<int>> MatVector(Col_park_size, std::vector<int>(Row_park_size, 0));
	for (size_t i = 0; i < Col_park_size; i++)
	{
		for (size_t j = 0; j < Row_park_size; j++)
		{
			if ("-1" == park[i][j])
			{
				MatVector[i][j] = 1;
			}
		}
	}

	for (size_t i = 1; i < Col_park_size; i++)
	{
		for (size_t j = 1; j < Row_park_size; j++)
		{
			// 현재 위치가 0이면 (다른 돗자리 존재) continue;
			if (0 == MatVector[i][j])
			{
				continue;
			}

			// 대각선, 좌, 상 중 가장 작은 값 + 1 저장
			MatVector[i][j] =
				std::min({
				MatVector[i - 1][j - 1] ,
				MatVector[i][j - 1],
				MatVector[i - 1][j] }) + 1;

			// 현재 값 set에 저장
			MatSet.insert(MatVector[i][j]);
		}
	}

	// for문 돌면서 set과 돗자리 크기 비교
	for (const int MatrixValue : mats)
	{
		if (MatSet.end() != MatSet.find(MatrixValue))
		{
			return MatrixValue;
		}
	}

	return answer;
}