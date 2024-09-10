#include <vector>

//¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12941

using namespace std;

#include <algorithm>
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    const size_t A_size = A.size();
    if (A_size != B.size())
    {
        return -1;
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), std::greater<int>());

    for (size_t i = 0; i < A_size; i++)
    {
        answer += A[i] * B[i];
    }

    return answer;
}