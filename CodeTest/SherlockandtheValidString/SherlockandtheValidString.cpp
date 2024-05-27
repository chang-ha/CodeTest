#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
#include <unordered_set>

string isValid(string s) 
{
    std::unordered_set<int> AlphabatCheck;

    for (const char _CurAlphabat : s)
    {
        AlphabatCheck.insert(_CurAlphabat);
    }
    int a = 0;
}

int main()
{
    string s;
    getline(cin, s);

    string result = isValid(s);

    cout << result << "\n";

    return 0;
}
