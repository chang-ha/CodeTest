#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/12953

using namespace std;

// �� ���� �� = �ִ� ����� * �ּ� �����
// �ִ� ����� = ��Ŭ���� ȣ����
// �ּ� ����� = �� ���� �� / �ִ� �����

int EuclideanAlgorithm(int A, int B)
{
    int BiggerValue = A > B ? A : B;
    int SmallerValue = A <= B ? A : B;
    int RemainValue = 1;

    while (0 != RemainValue)
    {
        RemainValue = BiggerValue % SmallerValue;
        BiggerValue = SmallerValue;
        SmallerValue = RemainValue;
    }

    return BiggerValue;
}

int solution(vector<int> arr)
{
    const size_t arr_size = arr.size();

    if (0 == arr_size)
    {
        return -1;
    }

    if (1 == arr_size)
    {
        return arr[0];
    }

    int answer = arr[0];
    for (size_t i = 1; i < arr_size; i++)
    {
        int GCD = EuclideanAlgorithm(answer, arr[i]);
        answer = answer * arr[i] / GCD;
    }

    return answer;
}
