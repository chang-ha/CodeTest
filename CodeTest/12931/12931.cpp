#include <iostream>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/12931

using namespace std;
int solution(int n)
{
    int answer = 0;

	while (0 != n)
	{
		answer += n % 10;
		n /= 10;
	}

    return answer;
}