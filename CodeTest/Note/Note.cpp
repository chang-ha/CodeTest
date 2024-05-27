#include <bits/stdc++.h>

using namespace std;


#include <unordered_map>
string isValid(const string s)
{
    std::unordered_map<char, int> AlphabatCheck;
    for (const char _CurAlphabat : s)
    {
        AlphabatCheck[_CurAlphabat] += 1;
    }

    std::map<int, int> AlphabatNumberCheck;
    for (const std::pair<char, int>& _CurAlphabat : AlphabatCheck)
    {
        AlphabatNumberCheck[_CurAlphabat.second] += 1;
    }

    size_t NumberSize = AlphabatNumberCheck.size();
    if (1 == NumberSize)
    {
        return "YES";
    }
    else if (3 <= NumberSize)
    {
        return "NO";
    }

    std::map<int, int>::iterator LowerNumber = AlphabatNumberCheck.begin();
    std::map<int, int>::reverse_iterator BiggerNumber = AlphabatNumberCheck.rbegin();

    int LowerNumberValue = LowerNumber->first;
    int BiggerNumberValue = BiggerNumber->first;
    int LowerNumberCount = LowerNumber->second;
    int BiggerNumberCount = BiggerNumber->second;

    if (1 == BiggerNumberValue - LowerNumberValue && (1 == LowerNumberCount || 1 == BiggerNumberCount))
    {
        return "YES";
    }

    if (1 == LowerNumberValue && 1 == LowerNumberCount)
    {
        return "YES";
    }

    return "NO";
}

int main()
{
    isValid("aaaaabc");
}