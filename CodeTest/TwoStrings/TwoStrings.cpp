#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

#include <unordered_set>
string twoStrings(string s1, string s2)
{
    std::unordered_set<char> s1Word;
    std::unordered_set<char> s2Word;

    int s1Size = static_cast<int>(s1.size());
    int s2Size = static_cast<int>(s2.size());

    for (int i = 0; i < s1Size; i++)
    {
        s1Word.insert(s1[i]);
    }

    for (int i = 0; i < s2Size; i++)
    {
        s2Word.insert(s2[i]);
    }

    std::unordered_set<char>::const_iterator CantFindIter = s2Word.end();
    for (char _CurWord : s1Word)
    {
        if (CantFindIter != s2Word.find(_CurWord))
        {
            return "YES";
        }
    }

    return "NO";
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
    }

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
