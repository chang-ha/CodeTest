#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void Merge(vector<int>& _InputVector, const int _Left, const int _Middle, const int _Right, long& _InversionCount)
{
    const int LeftVectorSize = _Middle - _Left + 1;
    const int RightVectorSize = _Right - _Middle;

    vector<int> LeftVector(LeftVectorSize);
    vector<int> RightVector(RightVectorSize);

    for (int i = 0; i < LeftVectorSize; i++)
    {
        LeftVector[i] = _InputVector[_Left + i];
    }

    for (int j = 0; j < RightVectorSize; j++)
    {
        RightVector[j] = _InputVector[_Middle + 1 + j];
    }

    int LeftVectorIndex = 0;
    int RightVectorIndex = 0;
    int ResultVectorIndex = _Left;

    while (LeftVectorIndex < LeftVectorSize && RightVectorIndex < RightVectorSize)
    {
        if (LeftVector[LeftVectorIndex] <= RightVector[RightVectorIndex])
        {
            _InputVector[ResultVectorIndex] = LeftVector[LeftVectorIndex];
            ++LeftVectorIndex;
        }
        else
        {
            // Swap Inversions
            _InputVector[ResultVectorIndex] = RightVector[RightVectorIndex];
            ++RightVectorIndex;
            _InversionCount += LeftVectorSize - LeftVectorIndex;
        }
        ++ResultVectorIndex;
    }

    while (LeftVectorIndex < LeftVectorSize)
    {
        _InputVector[ResultVectorIndex] = LeftVector[LeftVectorIndex];
        LeftVectorIndex++;
        ResultVectorIndex++;
    }

    while (RightVectorIndex < RightVectorSize)
    {
        _InputVector[ResultVectorIndex] = RightVector[RightVectorIndex];
        RightVectorIndex++;
        ResultVectorIndex++;
    }
}

void MergeSort(vector<int>& _InputVector, const int _Begin, const int _End, long& _InversionCount)
{
    if (_Begin >= _End)
    {
        return;
    }

    int Middle = _Begin + (_End - _Begin) / 2;
    MergeSort(_InputVector, _Begin, Middle, _InversionCount);
    MergeSort(_InputVector, Middle + 1, _End, _InversionCount);
    Merge(_InputVector, _Begin, Middle, _End, _InversionCount);
}

long countInversions(vector<int> arr)
{
    long InversionsCount = 0;
    MergeSort(arr, 0, static_cast<int>(arr.size()) - 1, InversionsCount);

    return InversionsCount;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

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
