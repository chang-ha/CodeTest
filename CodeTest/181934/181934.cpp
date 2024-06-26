#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m)
{
    int answer = 0;
    if (ineq != "<" && ineq != ">")
    {
        // Error
        return answer;
    }

    if (eq != "=" && eq != "!")
    {
        // Error
        return answer;
    }

    switch (ineq[0])
    {
    case '<':
        answer = n < m ? 1 : 0;
        break;
    case '>':
        answer = n > m ? 1 : 0;
        break;
    default:
        // Error
        return answer;
    }

    if (1 == answer)
    {
        return answer;
    }

    switch (eq[0])
    {
    case '=':
        answer = n == m ? 1 : 0;
        break;
    case '!':
    default:
        // Error
        return answer;
    }

    return answer;
}