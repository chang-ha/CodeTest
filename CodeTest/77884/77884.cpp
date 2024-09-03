#include <string>
#include <vector>

using namespace std;

#include <cmath>
int CalcuDivisor(const int _Value)
{
	int answer = 0;
	const int squrt_value = static_cast<int>(std::sqrt(_Value));

	for (int i = 1; i <= squrt_value; i++)
	{
		answer += _Value % i == 0 ? 2 : 0;
	}

	if (_Value == squrt_value * squrt_value)
	{
		--answer;
	}

	return answer;
}

int solution(int left, int right)
{
	int answer = 0;

	for (int i = left; i <= right; i++)
	{
		answer += CalcuDivisor(i) % 2 == 0 ? i : -i;
	}

	return answer;
}
