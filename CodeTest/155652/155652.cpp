#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index)
{
    string answer = "";

    int WordRange = 'z' - 'a' + 1;
    std::vector<bool> SkipVector(WordRange);

    for (const char _CurChar : skip)
    {
        SkipVector[_CurChar - 'a'] = true;
    }

    for (const char _CurChar : s)
    {
        char _NextChar = _CurChar;
        for (int i = 0; i < index;)
        {
            ++_NextChar;
            if ('z' < _NextChar)
            {
                _NextChar -= WordRange;
            }

            if (true == SkipVector[_NextChar - 'a'])
            {
                continue;
            }

            ++i;
        }
        answer += _NextChar;
    }
    return answer;
}