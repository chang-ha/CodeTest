#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12947

using namespace std;

bool solution(int x) 
{
    if (0 == x)
    {
        return false;
    }

    int CalcuDigit = x;
    int Digits = 0;

    while (0 != CalcuDigit)
    {
        Digits += CalcuDigit % 10;
        CalcuDigit /= 10;
    }

    return x % Digits == 0 ? true : false;
}