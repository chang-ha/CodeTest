#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12924

using namespace std;

int solution(int n) 
{
    int answer = 1; // n = n

    const int Half_n = n / 2;
    for (int i = 1; i <= Half_n; i++)
    {
        int SumValue = i;
        for (int j = i + 1; j <= Half_n + 1; j++)
        {
            SumValue += j;
            if (n <= SumValue)
            {
                break;
            }
        }

        if (n == SumValue)
        {
            ++answer;
        }
    }

    return answer;
}

int solution(int n)
{
    int pivot = n & -n;
    int before = ((n ^ (n + pivot)) / pivot) >> 2;
    return (n + pivot) | before;
}