#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/12914

using namespace std;

// 1ĭ = 1
// 1
// 2ĭ = 2
// 1 1
// 2
// 3ĭ = 3 -> (1ĭ�� ��쿡�� 2ĭ ����) + (2ĭ�� ��쿡�� 1ĭ ����)
// 1 1 1
// 2 1
// 1 2
// 4ĭ = 5 -> (2ĭ�� ��쿡�� 2ĭ ����) + (3ĭ�� ��쿡�� 1ĭ ����)
// 1 1 1 1
// 2 1 1
// 1 2 1
// 1 1 2
// 2 2

long long solution(int n)
{
	long long First = 1;
	long long Second = 2;
	long long Third = 3;

	if (1 == n)
	{
		return 1;
	}

	if (2 == n)
	{
		return 2;
	}

	for (int i = 2; i < n; i++)
	{
		Third = (First + Second) % 1234567;
		First = Second % 1234567;
		Second = Third;
	}

	return Third;
}