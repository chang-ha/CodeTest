#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/64065

using namespace std;

// 1�� ���� , = 0
// 2�� ���� , = 0 + ���� �޸� 1 + 2�� ���� ���� �޸� 1 = 2
// 3�� ���� , = 0 + 2�� ���� 2 + ���� �޸� 1 + 3�� ���� ���� �޸� 2 = 0 + 2 + 3
// 4�� ���� , = 0 + 2 + 3 + ���� �޸� 1 + 4�� ���� ���� �޸� 3 = 0 + 2 + 3 + 4 

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