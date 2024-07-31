#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts)
{
	string answer = "";

	size_t Parts_Size = parts.size();
	for (size_t i = 0; i < Parts_Size; i++)
	{
		answer.append(my_strings[i].begin() + parts[i][0], my_strings[i].begin() + parts[i][1] + 1);
	}

	return answer;
}