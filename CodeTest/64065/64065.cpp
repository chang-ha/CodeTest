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

// { ���� - 1 -> Ʃ�� ����

#include <algorithm>
#include <stdexcept>
#include <map>
vector<int> solution(string s)
{
	vector<int> answer;
	const size_t countOfBrace = std::count(s.begin(), s.end(), '{');
	if (0 == countOfBrace)
	{
		// Error
		throw std::invalid_argument("check your argument");
	}
	answer.resize(countOfBrace - 1);

	std::map<int, int> TupleMap;
	std::string CalcuString = "";
	for (const char CurChar : s)
	{
		if (0 != std::isalnum(CurChar))
		{
			CalcuString += CurChar;
		}
		else if ("" != CalcuString)
		{
			TupleMap[std::stoi(CalcuString)] += 1;
			CalcuString = "";
		}
	}

	for (const std::pair<int, int>& CurPair : TupleMap)
	{
		answer[countOfBrace - 1 - CurPair.second] = CurPair.first;
	}

	return answer;
}