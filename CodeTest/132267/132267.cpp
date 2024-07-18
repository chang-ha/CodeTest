#include <string>
#include <vector>

using namespace std;

int Otherssolution(int a, int b, int n)
{
    // 1) �� �� ��ȯ�� ��ü ����(n)���� (a - b)��ŭ ������ �پ��
    // 2) �ܼ��ϰ� ��ü ���� / �پ��� ���� * ���� ���� -> n / (a - b) * b
    // 3) �̷��� ����ϸ� n < a �� ��쿡 ������ �߻��� �� ���� (�����ؾ��ϴ� �ݶ��� ���� ����)
    // 4) ���� k�� ��ȯ�� �� �ִٸ� -> n / (a - b) * b 
    //    -> k - 1 �� ��ȯ + 1�� ��ȯ -> (n - a) / (a - b) * b + b;
    //    -> k - 1 �� ��ȯ�ϴ� �κ��� �������� ����ϸ� ��
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