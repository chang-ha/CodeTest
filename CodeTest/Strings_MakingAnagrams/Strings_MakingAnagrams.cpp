#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

 // CountingSort
int makeAnagram(string a, string b)
{
	int DeleteCount = 0;

	int StringCount = 'z' - 'a' + 1;
	std::vector<int> Count_a(StringCount);
	std::vector<int> Count_b(StringCount);

	for (char _CurChar : a)
	{
		if ('a' > _CurChar || 'z' < _CurChar)
		{
			// Error
			return -1;
		}
		Count_a[_CurChar - 'a'] += 1;
	}

	for (char _CurChar : b)
	{
		if ('a' > _CurChar || 'z' < _CurChar)
		{
			// Error
			return -1;
		}
		Count_b[_CurChar - 'a'] += 1;
	}

	for (int i = 0; i < StringCount; i++)
	{
		DeleteCount += std::abs(Count_a[i] - Count_b[i]);
	}

	return DeleteCount;
}

int main()
{
    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    cout << res << "\n";

    return 0;
}
