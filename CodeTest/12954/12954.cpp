#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12954

using namespace std;

vector<long long> solution(int x, int n) 
{
    vector<long long> answer;
    answer.reserve(n);
    long long ll_x = static_cast<long long>(x);

    for (int i = 1; i <= n; i++)
    {
        answer.push_back(ll_x * i);
    }

    return answer;
}