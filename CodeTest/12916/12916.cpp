#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int P_Count = 0;
    int Y_Count = 0;

    for (const char _CurChar : s)
    {
        if ('p' == _CurChar ||
            'P' == _CurChar)
        {
            ++P_Count;
        }
        else if ('y' == _CurChar ||
            'Y' == _CurChar)
        {
            ++Y_Count;
        }
    }

    return P_Count == Y_Count ? true : false;
}