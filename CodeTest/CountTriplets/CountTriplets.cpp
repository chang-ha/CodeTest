#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

// Complete the countTriplets function below.
#include <unordered_map>
long countTriplets(vector<long> arr, long r)
{
    long CountValue = 0;

    std::unordered_map<long, long> LeftValues;
    std::unordered_map<long, long> RightValues;

    for (long i : arr)
    {
        RightValues[i] += 1;
    }

    for (long CurValue : arr)
    {
        RightValues[CurValue] -= 1;

        if (0 != CurValue % r)
        {
            LeftValues[CurValue] += 1;
            continue;
        }

        long LeftValue = CurValue / r;
        long RightValue = CurValue * r;

        if (LeftValues.end() != LeftValues.find(LeftValue) &&
            RightValues.end() != RightValues.find(RightValue))
        {
            CountValue += LeftValues[LeftValue] * RightValues[RightValue];
        }

        LeftValues[CurValue] += 1;
    }

    return CountValue;
}

int main()
{
    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    cout << ans << "\n";

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
