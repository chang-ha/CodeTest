#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/87390

using namespace std;

// 1 2 3 4
// 2 2 3 4
// 3 3 3 4
// 4 4 4 4

// 1 : 0, 0 
// 2 : 0, 1 / 1, 0 / 1, 1
// 3 : 0, 2 / 1, 2 / 2, 0 / 2, 1 / 2, 2 / 
// 4 : 0, 3 / 1, 3 / 2, 3 / 3, 3 / 3, 0 / 3, 1 / 3, 2

// left = 7 -> 7 / n , 7 % n -> 1, 3
// right = 14 -> 3, 2

vector<int> solution(int n, long long left, long long right)
{
	if (0 > left)
	{
		return { -1 };
	}

	long long MaxValue = n;
	MaxValue *= n;
	if (MaxValue <= right)
	{
		return { -1 };
	}

	vector<int> answer;
	answer.reserve(right - left + 1);

	for (long long i = left; i <= right; i++)
	{
		const long long ColIndex = i / n;
		const long long RowIndex = i % n;
		answer.push_back(static_cast<int>(std::max(ColIndex, RowIndex) + 1));
	}

	return answer;
}