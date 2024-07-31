#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix)
{
	size_t Prefix_Size = is_prefix.size();
	if (my_string.size() < Prefix_Size)
	{
		return 0;
	}

	if (my_string.substr(0, Prefix_Size) == is_prefix)
	{
		return 1;
	}
	return 0;
}