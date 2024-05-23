#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */


// prefix sum ���빮��
long arrayManipulation(int n, vector<vector<int>> queries)
{
    std::vector<int> PreFixSumVector(n);
    int QueriesSize = static_cast<int>(queries.size());

    for (int i = 0; i < QueriesSize; i++)
    {
        int QueriesLeftIndex = queries[i][0];
        int QueriesRightyIndex = queries[i][1];
        int QueriesSum = queries[i][2];

        if (0 > QueriesLeftIndex - 1)
        {
            // Error
            return -1;
        }
        else
        {
            PreFixSumVector[QueriesLeftIndex - 1] += QueriesSum;
        }

        if (n < QueriesRightyIndex)
        {
            // Error
            return -1;
        }
        else if (n == QueriesRightyIndex)
        {
            continue;
        }
        else
        {
            // �̹� �������� ������ �������� �ƴ� ������ �ִ밪�� ���ϴ� ������
            // ������ ������ : PreFixSumVector[QueriesLeftIndex + 1] = PreFixSumVector[QueriesLeftIndex] + QueriesSum;
            // ������ �ִ밪 : PreFixSumVector[QueriesLeftIndex] = QueriesSum;
            // && �ִ밪�� ���ϴ� ���̱� ������ ������ ���� 0�� �Ǿ���� => PreFixSumVector[QueriesRightIndex + 1] = - QueriesSum;
            // -> �Ʒ����� ��� ������ ���ҵ��� �����ֱ� ������ ������ 0�� �Ǿ����
            // -> �츮�� ���ϴ°� �������� �ƴ� ������ �ִ밪
            PreFixSumVector[QueriesRightyIndex] -= QueriesSum;
        }
    }

    long SumValue = 0;
    long ResultValue = 0;
    for (int i = 0; i < n; i++)
    {
        SumValue += PreFixSumVector[i];
        ResultValue = std::max(SumValue, ResultValue);
    }
    return ResultValue;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

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
