#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y)
{
	string answer = "";

	// Vector에 문자열 갯수 저장
	std::vector<int> X_Vector(10);
	for (const char _CurChar : X)
	{
		X_Vector[_CurChar - '0'] += 1;
	}

	std::vector<int> Y_Vector(10);
	for (const char _CurChar : Y)
	{
		Y_Vector[_CurChar - '0'] += 1;
	}

	// 가장 큰 수를 구해야 하니 9부터 for loop
	// 두 벡터중 숫자가 적은 값 == 공통 갯수
	// 공통 갯수만큼 answer 문자열에 추가
	for (int i = 9; i >= 0; i--)
	{
		answer.append(std::min(X_Vector[i], Y_Vector[i]), '0' + i);
	}

	// 공통된 수가 없을 때
	if ("" == answer)
	{
		answer = "-1";
	}
	
	// 공통된 수가 0뿐일 때
	if (answer.begin() != answer.end() &&
		'0' == *answer.begin())
	{
		answer = "0";
	}

	return answer;
}