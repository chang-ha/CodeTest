
// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12980

using namespace std;

// 5000
// 5000 / 2 = 2500
// 2500 / 2 = 1250
// 1250 / 2 = 625
// 625 - 1 = 624  -> 1
// 624 / 2 = 312
// 312 /2 = 156
// 156 / 2 = 78
// 78 / 2 = 39
// 39 - 1 = 38 -> 1
// 38 / 2 = 19
// 19 - 1 = 18 -> 1
// 18 /2 = 9
// 9 - 1 = 8 -> 1
// 8 / 2 = 4
// 4 / 2 = 2
// 2 / 2 = 1
// 1 - 1 -> 1
// 5

int solution(int n)
{
    int ans = 0; 
    while (0 != n)
    {
        ans += n % 2;
        n /= 2;

        //switch (n % 2)
        //{
        //case 1:
        //    ans += 1;
        //    n -= 1;
        //    break;
        //case 0:
        //    n /= 2;
        //    break;
        //}
    }
    return ans;
}