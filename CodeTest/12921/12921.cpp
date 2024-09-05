#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/12921

using namespace std;

#include <cmath>
int solution(int n) {
    // n - 1�� ���� ���� (1 �����ϰ� ����)
    int answer = n - 1;

    // �����佺�׳׽��� ü
    std::vector<bool> Eratosthenes(n + 1, true);
    Eratosthenes[0] = false;
    Eratosthenes[1] = false;

    int sqrt_n = static_cast<int>(std::sqrt(n));

    // 5
    // 2 3 5 7 9

    for (int i = 2; i <= sqrt_n; i++)
    {
        // j = i * i ���� �˻��ϸ� ��
        // j = i * 2 ���� ���ϴ� ������ ���� i ���� (i - 1) * i ���� �˻��ϱ� ����
        // ex) i = 3�� ��, �̹� 2�� ������� �˻��Ͽ��� ������ j = 3 * 2 ���� �˻� X / j = 3 * 3 ���� �˻� 
        for (int j = i * i; j <= n; j += i)
        {
            // n���� �Ҽ� ���� ����
            if (true == Eratosthenes[j])
            {
                --answer;
            }
            Eratosthenes[j] = false;
        }
    }

    return answer;
}