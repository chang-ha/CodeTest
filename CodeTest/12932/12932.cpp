#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/12932

using namespace std;

vector<int> solution(long long n) 
{
    vector<int> answer;
    // long long �ִ� �ڸ���
    answer.reserve(19);

    while (0 != n)
    {
        answer.push_back(n % 10);
        n /= 10;
    }
    
    return answer;
}