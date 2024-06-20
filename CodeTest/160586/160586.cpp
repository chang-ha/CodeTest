#include <string>
#include <vector>

using namespace std;

#include <limits.h>
vector<int> solution(vector<string> keymap, vector<string> targets)
{
    size_t Targets_Size = targets.size();
    vector<int> answer(Targets_Size, 0);

    vector<int> MinKey_Vector('Z' - 'A' + 1, INT_MAX);

    for (const std::string& _CurKey : keymap)
    {
        size_t _CurKey_Size = static_cast<int>(_CurKey.size());
        for (int i = 0; i < _CurKey_Size; i++)
        {
            int CurIndex = _CurKey[i] - 'A';
            if (i < MinKey_Vector[CurIndex])
            {
                MinKey_Vector[CurIndex] = i + 1;
            }
        }
    }

    for (size_t i = 0; i < Targets_Size; i++)
    {
        for (const char _CurTarget : targets[i])
        {
            int CurIndex = _CurTarget - 'A';

            if (INT_MAX == MinKey_Vector[CurIndex])
            {
                answer[i] = -1;
                break;
            }
            answer[i] += MinKey_Vector[CurIndex];
        }
    }

    return answer;
}