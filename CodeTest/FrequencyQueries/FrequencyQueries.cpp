#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

// Complete the freqQuery function below.
#include <unordered_map>
vector<int> freqQuery(vector<vector<int>> queries)
{
	std::unordered_map<int, int> Value_FrequencyMap;
	std::unordered_map<int, int> FrequencyMap;
	std::vector<int> ResultVector;

	for (vector<int> CurQueries : queries)
	{
		if (2 < CurQueries.size())
		{
			// Error
			return ResultVector;
		}

		switch (CurQueries[0])
		{
		case 1:
		{
			if (Value_FrequencyMap.end() == Value_FrequencyMap.find(CurQueries[1]))
			{
				++Value_FrequencyMap[CurQueries[1]];
				++FrequencyMap[1];
				continue;
			}

			int& CurFrequency = Value_FrequencyMap[CurQueries[1]];

			--FrequencyMap[CurFrequency];
			++CurFrequency;
			++FrequencyMap[CurFrequency];
			break;
		}
		case 2:
		{
			if (Value_FrequencyMap.end() == Value_FrequencyMap.find(CurQueries[1]))
			{
				break;
			}

			int& CurFrequency = Value_FrequencyMap[CurQueries[1]];

			--FrequencyMap[CurFrequency];
			--CurFrequency;

			if (0 != CurFrequency)
			{
				++FrequencyMap[CurFrequency];
			}
			else
			{
				Value_FrequencyMap.erase(CurQueries[1]);
			}
			break;
		}
		case 3:
		{
			bool IsContains = 0 != FrequencyMap[CurQueries[1]] ? true : false;
			ResultVector.push_back(IsContains);
			break;
		}
		default:
			// Error
			return ResultVector;
		}
	}

	return ResultVector;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];

        if (i != ans.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

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
