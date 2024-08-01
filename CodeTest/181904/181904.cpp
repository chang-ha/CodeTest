#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) 
{
    string answer = "";

	size_t String_Size = my_string.size();

	if (0 == c)
	{
		return "Error";
	}

	for (size_t i = c - 1; i < String_Size; i+= m)
	{
		answer += my_string.at(i);
	}

    return answer;
}