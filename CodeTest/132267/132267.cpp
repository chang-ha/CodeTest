#include <string>
#include <vector>

using namespace std;

int Otherssolution(int a, int b, int n)
{
    // 1) 한 번 교환시 전체 갯수(n)에서 (a - b)만큼 갯수가 줄어듬
    // 2) 단순하게 전체 갯수 / 줄어드는 갯수 * 지급 갯수 -> n / (a - b) * b
    // 3) 이렇게 계산하면 n < a 일 경우에 문제가 발생할 수 있음 (지급해야하는 콜라병의 갯수 부족)
    // 4) 만약 k번 교환할 수 있다면 -> n / (a - b) * b 
    //    -> k - 1 번 교환 + 1번 교환 -> (n - a) / (a - b) * b + b;
    //    -> k - 1 번 교환하는 부분은 내림으로 계산하면 됨
    // 5) b * ( (n - a) / (a - b) + 1) -> b * ( (n - a + a - b) / (a - b) ) 
    // (n - b) / (a - b) * b
    return (n > b ? n - b : 0) / (a - b) * b;
}

int Whilesolution(int a, int b, int n)
{
    int answer = 0;

    if (b > n)
    {
        return answer;
    }

    if (b > a)
    {
        // infinite loop
        return -1;
    }

    while (n >= a)
    {
        int PayBackBottle = n / a * b;
        int RemainBottle = n % a;
        answer += PayBackBottle;
        n = PayBackBottle + RemainBottle;
    }

    return answer;
}