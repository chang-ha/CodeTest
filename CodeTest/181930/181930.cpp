#include <string>
#include <vector>

using namespace std;

#include <cmath>
#include <algorithm>
#include <set>
int solution(int a, int b, int c)
{
    int answer = 1;

    // vector
    std::vector<int> ValueVector(7);
    // set
    // std::set<int> ValueSet({a,b,c});

    ValueVector[a] += 1;
    ValueVector[b] += 1;
    ValueVector[c] += 1;

    int SameValueCount = std::max({ ValueVector[a], ValueVector[b], ValueVector[c] });

    switch (SameValueCount)
    {
    case 3:
        answer *= static_cast<int>((std::pow(a, 3) + std::pow(b, 3) + std::pow(c, 3)));
    case 2:
        answer *= static_cast<int>((std::pow(a, 2) + std::pow(b, 2) + std::pow(c, 2)));
    case 1:
        answer *= (a + b + c);
    default:
        break;
    }

    return answer;
}