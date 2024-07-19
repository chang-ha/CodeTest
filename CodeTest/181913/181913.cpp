#include <string>
#include <vector>

using namespace std;

#include <numeric>
string solution(string my_string, vector<vector<int>> queries)
{
	string answer = my_string;
	int String_Size = static_cast<int>(my_string.size());

	std::vector<int> StringIndex_Vector(String_Size);
	std::iota(StringIndex_Vector.begin(), StringIndex_Vector.end(), 0);

	for (const std::vector<int>& _CurQueries : queries)
	{
		for (int i = _CurQueries[0]; i < _CurQueries[1]; i++)
		{
			StringIndex_Vector[_CurQueries[1]] = _CurQueries[0];
		}
	}

	for (int i = 0; i < String_Size; ++i)
	{
		answer[i] = my_string[StringIndex_Vector[i]];
	}

	return answer;
}