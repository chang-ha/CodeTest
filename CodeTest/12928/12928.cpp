#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12928

using namespace std;

#include <cmath>
int solution(int n) 
{
    int answer = 0;
	
	int sqrt_n = static_cast<int>(std::sqrt(n));
	for (int i = 1; i <= sqrt_n; i++)
	{
		if (0 == n % i)
		{
			answer += i;
			answer += n / i;
		}
	}

	if (n == sqrt_n * sqrt_n)
	{
		answer -= sqrt_n;
	}

    return answer;
}