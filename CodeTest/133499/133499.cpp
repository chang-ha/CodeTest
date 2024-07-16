#include <string>
#include <vector>

using namespace std;

bool CheckBabbling(std::string& _Babbling)
{
    static vector<std::string> Canbabbling = { "aya", "ye", "woo", "ma" };

    int SubstrIndex = 0;
    int BabblingIndex = -1;
    char PrevBabbling = ' ';
    char CurBabbling = ' ';
    while (true)
    {
        if (true == _Babbling.empty())
        {
            return true;
        }

        CurBabbling = _Babbling.front();
        if (PrevBabbling == CurBabbling)
        {
            return false;
        }

        if ('a' == CurBabbling)
        {
            SubstrIndex = 3;
            BabblingIndex = 0;
        }
        else if ('w' == CurBabbling)
        {
            SubstrIndex = 3;
            BabblingIndex = 2;
        }
        else if ('y' == CurBabbling)
        {
            SubstrIndex = 2;
            BabblingIndex = 1;
        }
        else if ('m' == CurBabbling)
        {
            SubstrIndex = 2;
            BabblingIndex = 3;
        }
        else
        {
            // Can't Babbling
            return false;
        }

        if (Canbabbling[BabblingIndex] == _Babbling.substr(0, SubstrIndex))
        {
            _Babbling.erase(0, SubstrIndex);
            PrevBabbling = CurBabbling;
        }
        else
        {
            return false;
        }
    }

}

int solution(vector<string> babbling)
{
    int answer = 0;

    for (std::string& _Curbabbling : babbling)
    {
        if (true == CheckBabbling(_Curbabbling))
        {
            ++answer;
        }
    }

    return answer;
}