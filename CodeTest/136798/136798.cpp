#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power)
{
    int answer = 0;

    std::vector<int> DivisorsVector(number + 1, 0);

    // 1부터 number까지 약수 갯수 구하기
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j * i <= number; j++)
        {
            DivisorsVector[i * j] += 1;
        }
    }

    for (const int _CurDivisorCount : DivisorsVector)
    {
        answer += limit < _CurDivisorCount ? power : _CurDivisorCount;
    }

    return answer;
}