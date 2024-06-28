#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// fast function
// Complete the triplets function below.
#include <algorithm>
long VectorSort_triplets(vector<int> a, vector<int> b, vector<int> c)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::sort(c.begin(), c.end());

    a.erase(std::unique(a.begin(), a.end()), a.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    c.erase(std::unique(c.begin(), c.end()), c.end());

    int i = 0, j = 0, k = 0;
    long sol = 0;

    while (i < b.size()) {
        while (a[j] <= b[i] && j < a.size())
            j++;
        while (c[k] <= b[i] && k < c.size())
            k++;
        sol += (long)j * k;
        i++;
    }
    return sol;
}

long Vector_triplets(vector<int> a, vector<int> b, vector<int> c)
{
    long Result = 0;

    std::set<int> A_Set(a.begin(), a.end());
    std::set<int> B_Set(b.begin(), b.end());
    std::set<int> C_Set(c.begin(), c.end());

    std::vector<int> A_Vector{ A_Set.begin(), A_Set.end() };
    std::vector<int> C_Vector{ C_Set.begin(), C_Set.end() };

    for (const int _CurB : B_Set)
    {
        if (_CurB < *A_Set.begin() || _CurB < *C_Set.begin())
        {
            continue;
        }
        std::vector<int>::const_iterator iterA = std::upper_bound(A_Vector.begin(), A_Vector.end(), _CurB);
        std::vector<int>::const_iterator iterC = std::upper_bound(C_Vector.begin(), C_Vector.end(), _CurB);
        size_t A_Count = iterA - A_Vector.begin();
        size_t C_Count = iterC - C_Vector.begin();

        Result += static_cast<long>(A_Count * C_Count);
    }

    return Result;
}

#include <set>
long triplets(const vector<int>& a, const vector<int>& b, const vector<int>& c)
{
    long Result = 0;

    std::set<int> B_Set;
    for (const int _CurValue : b)
    {
        B_Set.insert(_CurValue);
    }

    int B_Max = *B_Set.rbegin();

    std::set<int> A_Set;
    for (const int _CurValue : a)
    {
        if (B_Max < _CurValue)
        {
            continue;
        }
        A_Set.insert(_CurValue);
    }

    std::set<int> C_Set;
    for (const int _CurValue : c)
    {
        if (B_Max < _CurValue)
        {
            continue;
        }
        C_Set.insert(_CurValue);
    }

    for (const int _CurB : B_Set)
    {
        if (_CurB < *A_Set.begin() || _CurB < *C_Set.begin())
        {
            continue;
        }

        int A_Count = static_cast<int>(std::distance(A_Set.begin(), std::upper_bound(A_Set.begin(), A_Set.end(), _CurB)));
        int C_Count = static_cast<int>(std::distance(C_Set.begin(), std::upper_bound(C_Set.begin(), C_Set.end(), _CurB)));

        Result += A_Count * C_Count;
    }

    return Result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string lenaLenbLenc_temp;
    getline(cin, lenaLenbLenc_temp);

    vector<string> lenaLenbLenc = split_string(lenaLenbLenc_temp);

    int lena = stoi(lenaLenbLenc[0]);

    int lenb = stoi(lenaLenbLenc[1]);

    int lenc = stoi(lenaLenbLenc[2]);

    string arra_temp_temp;
    getline(cin, arra_temp_temp);

    vector<string> arra_temp = split_string(arra_temp_temp);

    vector<int> arra(lena);

    for (int i = 0; i < lena; i++) {
        int arra_item = stoi(arra_temp[i]);

        arra[i] = arra_item;
    }

    string arrb_temp_temp;
    getline(cin, arrb_temp_temp);

    vector<string> arrb_temp = split_string(arrb_temp_temp);

    vector<int> arrb(lenb);

    for (int i = 0; i < lenb; i++) {
        int arrb_item = stoi(arrb_temp[i]);

        arrb[i] = arrb_item;
    }

    string arrc_temp_temp;
    getline(cin, arrc_temp_temp);

    vector<string> arrc_temp = split_string(arrc_temp_temp);

    vector<int> arrc(lenc);

    for (int i = 0; i < lenc; i++) {
        int arrc_item = stoi(arrc_temp[i]);

        arrc[i] = arrc_item;
    }

    long ans = triplets(arra, arrb, arrc);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
        return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
