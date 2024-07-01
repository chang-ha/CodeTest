#include <string>
#include <vector>

using namespace std;
#include <unordered_map>

vector<int> Vectorsolution(string s)
{
	vector<int> answer;
	answer.reserve(s.size());

	vector<int> CharVector('z' - 'a' + 1, -1);

	int String_Size = static_cast<int>(s.size());

	for (int i = 0; i < String_Size; i++)
	{
		int Index = s[i] - 'a';
		if (-1 == CharVector[Index])
		{
			answer.push_back(-1);
		}
		else
		{
			answer.push_back(i - CharVector[Index]);
		}
		CharVector[Index] = i;
	}

	return answer;
}

vector<int> solution(string s)
{
	vector<int> answer;
	answer.reserve(s.size());

	std::unordered_map<char, int> PrevChar;
	int String_Size = static_cast<int>(s.size());

	for (int i = 0; i < String_Size; i++)
	{
		if (PrevChar.end() == PrevChar.find(s[i]))
		{
			PrevChar[s[i]] = i;
			answer.push_back(-1);
		}
		else
		{
			answer.push_back(i - PrevChar[s[i]]);
			PrevChar[s[i]] = i;
		}
	}

	return answer;
}