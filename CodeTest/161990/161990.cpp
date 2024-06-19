#include <string>
#include <vector>

using namespace std;

#include <algorithm>
#include <limits.h>

vector<int> solution(vector<string> wallpaper)
{
    vector<int> answer(4);
    answer[0] = answer[1] = INT_MAX;
    answer[2] = answer[3] = INT_MIN;

    size_t Wallpaper_Size = wallpaper.size();

    for (size_t i = 0; i < Wallpaper_Size; i++)
    {
        size_t PrevFile_XPos = wallpaper[i].find("#", 0);

        while (std::string::npos != PrevFile_XPos)
        {
            answer[0] = std::min(answer[0], static_cast<int>(i));
            answer[1] = std::min(answer[1], static_cast<int>(PrevFile_XPos));
            answer[2] = std::max(answer[2], static_cast<int>(i));
            answer[3] = std::max(answer[3], static_cast<int>(PrevFile_XPos));
            PrevFile_XPos = wallpaper[i].find("#", PrevFile_XPos + 1);
        }
    }

    answer[2] += 1;
    answer[3] += 1;

    return answer;
}