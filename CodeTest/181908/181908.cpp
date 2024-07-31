#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix)
{
	size_t Suffix_Size = is_suffix.size();
	size_t String_Size = my_string.size();
	if (String_Size < Suffix_Size)
	{
		return 0;
	}

	if (my_string.substr(String_Size - Suffix_Size) == is_suffix)
	{
		return 1;
	}
	return 0;
}