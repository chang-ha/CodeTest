#include <string>
#include <vector>

using namespace std;
#include <algorithm>

//#include <set>
//int solution(int n, int m, vector<int> section)
//{
//    int answer = 0;
//
//    std::sort(section.begin(), section.end());
//
//    if (n < *section.rbegin()
//        || 1 > *section.begin())
//    {
//        // Error
//        return answer;
//    }
//
//    std::set<int> mPackingSection;
//    mPackingSection.insert(section[0]);
//
//    for (const int _CurSection : section)
//    {
//        if (_CurSection >= *mPackingSection.rbegin() + m)
//        {
//            mPackingSection.insert(_CurSection);
//        }
//    }
//
//    answer = static_cast<int>(mPackingSection.size());
//
//    return answer;
//}

int solution(int n, int m, vector<int> section)
{
    int answer = 0;

    std::sort(section.begin(), section.end());

    if (n < *section.rbegin()
        || 1 > *section.begin())
    {
        // Error
        return answer;
    }

    int PrevSection = section[0];
    ++answer;

    for (const int _Cursection : section)
    {
        if (_Cursection >= PrevSection + m)
        {
            ++answer;
            PrevSection = _Cursection;
        }
    }

    return answer;
}