#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'reverseShuffleMerge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */


#include <map>
#include <unordered_map>
std::unordered_map<char, int> StringStruct(const string& _String)
{
	std::unordered_map<char, int> Result;

	for (const char _CurChar : _String)
	{
		Result[_CurChar] += 1;
	}

	return Result;
}

string reverseShuffleMerge(const string& s)
{
	string Result = "";

	std::unordered_map<char, int> WordCount = StringStruct(s);

	std::map<char, int> ResultWord;

	for (const std::pair<char, int>& _CurPair : WordCount)
	{
		int CurWordCount = _CurPair.second;
		if (0 != CurWordCount % 2)
		{
			// Error
			return Result;
		}

		ResultWord[_CurPair.first] = CurWordCount / 2;
	}

	string Reverse_S = s;
	std::reverse(Reverse_S.begin(), Reverse_S.end());

	std::map<char, int>::iterator StartIter = ResultWord.begin();
	std::map<char, int>::iterator EndIter = ResultWord.end();
	size_t PrevPos = -1;

	for (; StartIter != EndIter;)
	{
		char CurChar = StartIter->first;

		size_t CheckPos = Reverse_S.find_first_of(CurChar, PrevPos + 1);
		string RemainString = Reverse_S.substr(CheckPos);
		std::unordered_map<char, int> RemainStringWordCount = StringStruct(RemainString);

		bool AllRemain = true;
		for (const std::pair<char, int>& _CurPair : ResultWord)
		{
			if (RemainStringWordCount[_CurPair.first] < _CurPair.second)
			{
				AllRemain = false;
				break;
			}
		}

		if (false == AllRemain)
		{
			++StartIter;
			continue;
		}

		Result += CurChar;

		if (1 == StartIter->second)
		{
			ResultWord.erase(StartIter);
		}
		else
		{
			StartIter->second -= 1;
		}
		StartIter = ResultWord.begin();
		PrevPos = CheckPos;
	}

	return Result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
