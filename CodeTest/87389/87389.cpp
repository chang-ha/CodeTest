#include <string>
#include <vector>

using namespace std;

#include <cmath>
int solution(int n) 
{
    int answer = n - 1;

    int N_sqrt = static_cast<int>(std::sqrt(answer));

    for (int i = 2; i <= N_sqrt; i++)
    {
        if (0 == answer % i)
        {
            answer = i;
            break;
        }
    }

    return answer;
}