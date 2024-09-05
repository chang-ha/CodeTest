#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/12940

using namespace std;

vector<int> solution(int n, int m)
{
	// 최대공약수 <- 유클리드 호제법
	vector<int> answer;
	answer.reserve(2);

	int Dividend = n >= m ? n : m; // 큰 수
	int Divisor = n < m ? n : m; // 작은 수
	int Remain = Dividend % Divisor;
	while (0 != Remain)
	{
		Dividend = Divisor;
		Divisor = Remain;
		Remain = Dividend % Divisor;
	}

	// 최대공약수
	answer.push_back(Divisor);
	// 최소공배수 = 두 수의 곱 / 최대공약수
	answer.push_back(n * m / Divisor);

	return answer;
}