#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long long findACount(string s, long long n)
{
	long long sSize = static_cast<long long>(s.size());
	long long aCount = 0;
	if (n > sSize)
	{
		n = sSize;
	}

	for (int i = 0; i < n; ++i)
	{
		if ('a' != s[i])
		{
			continue;
		}

		++aCount;
	}

	return aCount;
}

long long repeatedString(string s, long long n)
{
	if (0 == n)
	{
		return 0;
	}

	if ("a" == s)
	{
		return n;
	}

	if (-1 == s.find('a'))
	{
		return 0;
	}

	std::string result = "";
	long long sSize = static_cast<long long>(s.size());
	long long Quotient = n / sSize;
	long long Remainder = n % sSize;
	long long aCount = 0;
	aCount += findACount(s, s.size()) * Quotient;
	aCount += findACount(s, Remainder);

	return aCount;
}


int main()
{
    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long long result = repeatedString(s, n);

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