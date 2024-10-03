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

// { 갯수 - 1 -> 튜플 갯수

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