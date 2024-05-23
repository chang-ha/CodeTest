#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'jumpingOnClouds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY c as parameter.
 */

int jumpingOnClouds(int size, vector<int> c) 
{
    if (0 >= size)
    {
        return 0;
    }

    if (size != c.size())
    {
        return 0;
    }

    if (1 == size)
    {
        return 0;
    }

    bool Isthunderheads1 = c[1];
    bool Isthunderheads2 = c[2];
    int InputSize = 0;
    vector<int> InputVector;
    int Result = 0;

    if (false == Isthunderheads2)
    {
        InputSize = size - 2;
        copy(c.begin() + 2, c.end(), back_inserter(InputVector));
    }
    else
    {
        InputSize = size - 1;
        copy(c.begin() + 1, c.end(), back_inserter(InputVector));
    }
    ++Result;

    Result += jumpingOnClouds(InputSize, InputVector);

    return Result;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(n, c);

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

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
