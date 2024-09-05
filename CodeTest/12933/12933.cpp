#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12933

using namespace std;

long long vectorsolution(long long n)
{
    std::vector<int> NumberVector(10, 0);

    while (0 != n)
    {
        NumberVector[n % 10] += 1;
        n /= 10;
    }

    long long answer = 0;

    const int NumberVector_size = static_cast<int>(NumberVector.size());
    for (int i = NumberVector_size - 1; i >= 0;)
    {
        if (0 == NumberVector[i])
        {
            i--;
            continue;
        }
        answer *= 10;
        answer += i;
        NumberVector[i] -= 1;
    }
    return answer;
}

#include <algorithm>
long long stringsolution(long long n) 
{
    std::string number_string = std::to_string(n);

    std::sort(number_string.begin(), number_string.end(), std::greater<char >());

    return std::stoll(number_string);
}