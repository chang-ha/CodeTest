#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

void minimumBribes(int n, vector<int> q)
{
	int InputVectorSize = static_cast<int>(q.size());
	if (n != InputVectorSize)
	{
		std::cout << "Too chaotic" << endl;
		return;
	}

	for (int i = 0; i < q.size(); i++)
	{
		if (2 < q[i] - (i + 1))
		{
			std::cout << "Too chaotic" << endl;
			return;
		}
	}

	vector<int> OrderVector(InputVectorSize);
	std::iota(OrderVector.begin(), OrderVector.end(), 1);
	int Index = 0;
	int TargetIndex = 0;
	int DiffIndex = 0;
	int MoveCount = 0;
	while (Index != InputVectorSize)
	{
		if (q[Index] == OrderVector[Index])
		{
			++Index;
			continue;
		}

		TargetIndex = Index;
		while (q[Index] != OrderVector[TargetIndex])
		{
			++TargetIndex;
			if (2 < ++DiffIndex)
			{
				std::cout << "Too chaotic" << endl;
				return;
			}
		}

		for (int i = 0; i < TargetIndex - Index; i++)
		{
			swap(OrderVector[TargetIndex - i], OrderVector[TargetIndex - (i + 1)]);
			++MoveCount;
		}

		DiffIndex = 0;
	}

	std::cout << MoveCount << endl;
	return;
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

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(n, q);
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
