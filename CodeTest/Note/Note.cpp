#include <TimeCheck\TimeCheck.h>
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

int main()
{
	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
			solution("rermgorpsam", {{2, 3}, { 0, 7 }, { 5, 9 }, { 6, 10 }});
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
		});

	int x = 0;
}