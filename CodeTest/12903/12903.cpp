#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
	const size_t s_size = s.size();

	if (0 == s_size % 2)
	{
		return s.substr(s_size / 2 - 1, 2);
	}

	return s.substr(s_size / 2, 1);
}