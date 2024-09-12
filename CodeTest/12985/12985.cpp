// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12985

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

	for (; a != b; ++answer)
	{
		if (0 != a % 2)
		{
			a += 1;
		}

		if (0 != b % 2)
		{
			b += 1;
		}

		a /= 2;
		b /= 2;
	}

    return answer;
}