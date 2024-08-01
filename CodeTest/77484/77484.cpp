#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    vector<int> answer(2, 7);

    vector<bool> LottosVector(46, false);

    for (const int _CurNumber : win_nums)
    {
        LottosVector[_CurNumber] = true;
    }

    for (const int _MyNumber : lottos)
    {
        if (0 == _MyNumber)
        {
            answer[0] -= 1;
            continue;
        }

        if (true == LottosVector[_MyNumber])
        {
            answer[0] -= 1;
            answer[1] -= 1;
        }
    }

    answer[0] = answer[0] == 7 ? answer[0] = 6 : answer[0];
    answer[1] = answer[1] == 7 ? answer[1] = 6 : answer[1];

    return answer;
}