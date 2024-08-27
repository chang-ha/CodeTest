#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

#include <algorithm>
int solution(vector<int> d, int budget) 
{
    int answer = 0;

    std::sort(d.begin(), d.end());

    for (const int CurValue : d)
    {
        if (budget >= CurValue)
        {
            budget -= CurValue;
            ++answer;
        }
        else
        {
            break;
        }
    }

    return answer;
}