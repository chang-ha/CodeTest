#include <cstring>
#include <string>
#include <vector>
using namespace std;

string solution(string my_string, string overwrite_string, int s)
{
	string answer = "";

	size_t my_string_size = my_string.size();
	size_t overwrite_string_size = overwrite_string.size();

	if (overwrite_string_size > my_string_size
		|| s > my_string_size - overwrite_string_size)
	{
		answer = "Error";
		return answer;
	}

	answer = my_string;

	std::memcpy(&answer[s], &overwrite_string[0], overwrite_string_size);

	return answer;
}

//string solution(string my_string, string overwrite_string, int s)
//{
//	string answer = "";
//	my_string.replace(s, overwrite_string.size(), overwrite_string);
//	answer = my_string;
//	return answer;
//}