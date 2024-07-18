#include <string>
#include <vector>

using namespace std;

// a b c d -> a -> size = 4
// a b c c -> a * b -> size = 3
// a a b b -> (a + b) * (a - b) -> size = 2
// a a a b -> (10 * a + b)^ 2 -> size = 2
// a a a a -> 1111 * a -> size = 1

#include <map>
#include <cmath>
int solution(int a, int b, int c, int d) 
{
    int answer = 1;
    std::map<int, int> DiceMap;
    DiceMap[a] += 1;
    DiceMap[b] += 1;
    DiceMap[c] += 1;
    DiceMap[d] += 1;

    std::map<int, int>::const_iterator FirstIter = DiceMap.begin();

    switch (DiceMap.size())
    {
    case 1:
        answer = 1111 * FirstIter->first;
        break;
    case 2:
    {
        std::map<int, int>::const_iterator SecondIter = DiceMap.begin();
        std::advance(SecondIter, 1);
        if (3 == FirstIter->second)
        {
            answer = std::pow((10 * FirstIter->first + SecondIter->first), 2);
        }
        else if (2 == FirstIter->second)
        {
            answer = (FirstIter->first + SecondIter->first) * (SecondIter->first - FirstIter->first);
        }
        else
        {
            answer = std::pow((10 * SecondIter->first + FirstIter->first), 2);
        }
        break;
    }
    case 3:
    {
        for (const std::pair<int, int>& _CurPair : DiceMap)
        {
            if (2 == _CurPair.second)
            {
                continue;
            }
            answer *= _CurPair.first;
        }
        break;
    }
    case 4:
        answer = FirstIter->first;
        break;
    default:
        // Error
        break;
    }


    return answer;
}