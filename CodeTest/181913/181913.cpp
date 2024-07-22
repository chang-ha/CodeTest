#include <string>
#include <vector>

using namespace std;

#include <algorithm>
string solution(string my_string, vector<vector<int>> queries)
{
	string answer = my_string;
	int String_Size = static_cast<int>(my_string.size());

	for (const std::vector<int>& _CurQueries : queries)
	{
		std::reverse(answer.begin() + _CurQueries[0], answer.begin() + _CurQueries[1] + 1);
	}

	return answer;
}