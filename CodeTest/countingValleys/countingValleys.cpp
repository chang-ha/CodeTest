#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) 
{
    bool Isvalley = false;
    int CurHeight = 0;
    int valleyCount = 0;

    for (int i = 0; 0 == path[i] ;)
    {
        if ('U' != path[i] || 'D' != path[i])
        {
            path.erase(i);
        }
        else
        {
            ++i;
        }
    }

    for (int i = 0; i < path.size(); i++)
    {
        if ('U' == path[i])
        {
            ++CurHeight;
            if (0 == CurHeight)
            {
                ++valleyCount;
            }
        }
        else if ('D' == path[i])
        {
            --CurHeight;
        }
    }

    return valleyCount;
}

int main()
{
    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    cout << result << "\n";

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
