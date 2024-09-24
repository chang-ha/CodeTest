#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/148653

using namespace std;

int solution(int storey)
{
	int answer = 0;

	while (0 < storey)
	{
		int Digit = storey % 10;
		storey /= 10;

		if (5 > Digit || (5 == Digit && 5 > storey % 10))
		{
			answer += Digit;
		}
		else
		{
			answer += 10 - Digit;
			storey += 1;
		}
	}

	return answer;
}