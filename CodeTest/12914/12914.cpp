#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12914

using namespace std;

// 1Ä­ = 1
// 1
// 2Ä­ = 2
// 1 1
// 2
// 3Ä­ = 3 -> (1Ä­ÀÇ °æ¿ì¿¡¼­ 2Ä­ Á¡ÇÁ) + (2Ä­ÀÇ °æ¿ì¿¡¼­ 1Ä­ Á¡ÇÁ)
// 1 1 1
// 2 1
// 1 2
// 4Ä­ = 5 -> (2Ä­ÀÇ °æ¿ì¿¡¼­ 2Ä­ Á¡ÇÁ) + (3Ä­ÀÇ °æ¿ì¿¡¼­ 1Ä­ Á¡ÇÁ)
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