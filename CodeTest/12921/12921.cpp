#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/12921

using namespace std;

#include <cmath>
int solution(int n) {
    // n - 1개 부터 시작 (1 제거하고 시작)
    int answer = n - 1;

    // 에라토스테네스의 체
    std::vector<bool> Eratosthenes(n + 1, true);
    Eratosthenes[0] = false;
    Eratosthenes[1] = false;

    int sqrt_n = static_cast<int>(std::sqrt(n));

    // 5
    // 2 3 5 7 9

    for (int i = 2; i <= sqrt_n; i++)
    {
        // j = i * i 부터 검사하면 됨
        // j = i * 2 부터 안하는 이유는 이전 i 들이 (i - 1) * i 까지 검사하기 때문
        // ex) i = 3일 때, 이미 2의 배수들은 검사하였기 때문에 j = 3 * 2 부터 검사 X / j = 3 * 3 부터 검사 
        for (int j = i * i; j <= n; j += i)
        {
            // n에서 소수 갯수 제거
            if (true == Eratosthenes[j])
            {
                --answer;
            }
            Eratosthenes[j] = false;
        }
    }

    return answer;
}