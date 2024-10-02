#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/64065

using namespace std;

// 1개 원소 , = 0
// 2개 원소 , = 0 + 구분 콤마 1 + 2개 원소 내부 콤마 1 = 2
// 3개 원소 , = 0 + 2개 원소 2 + 구분 콤마 1 + 3개 원소 내부 콤마 2 = 0 + 2 + 3
// 4개 원소 , = 0 + 2 + 3 + 구분 콤마 1 + 4개 원소 내부 콤마 3 = 0 + 2 + 3 + 4 

// n(n+1) / 2 = comma + 1
// n(n+1) = 2X + 2
// n^2 + n = 2 X + 2 
// n(n+1) = 110
// 

#include <algorithm>
vector<int> solution(string s)
{
	vector<int> answer;
	int countOfComma = std::count(s.begin(), s.end(), ',');
	// answer.reserve();

	return answer;
}