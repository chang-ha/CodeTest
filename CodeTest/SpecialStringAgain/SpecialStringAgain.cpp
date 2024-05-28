#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s)
{
    long Result = 0;

    std::vector<std::pair<char, int>> CountAlphabat;

    char PrevChar = s[0];
    char CurChar = ' ';
    int Count = 0;
    for (int i = 0; i < n; i++)
    {
        CurChar = s[i];
        if (PrevChar != CurChar)
        {
            CountAlphabat.push_back(std::make_pair(PrevChar, Count));
            PrevChar = CurChar;
            Count = 1;
        }
        else
        {
            ++Count;
            continue;
        }
    }
    CountAlphabat.push_back(std::make_pair(CurChar, Count));


    int VectorSize = static_cast<int>(CountAlphabat.size());
    for (std::pair<char, int> _CurPair : CountAlphabat)
    {
        int CurAlphabatCount = _CurPair.second;
        Result += CurAlphabatCount * (CurAlphabatCount + 1) / 2;
    }

    for (int i = 1; i < VectorSize - 1; i++)
    {
        std::pair<char, int> _PrevPair = CountAlphabat[i - 1];
        std::pair<char, int> _CurPair = CountAlphabat[i];
        std::pair<char, int> _NextPair = CountAlphabat[i + 1];

        if (_PrevPair.first != _NextPair.first)
        {
            continue;
        }

        if (1 != _CurPair.second)
        {
            continue;
        }

        Result += std::min(_PrevPair.second, _NextPair.second);
    }

    return Result;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    cout << result << "\n";

    return 0;
}
