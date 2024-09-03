#include <string>
#include <vector>

using namespace std;

int STLsolution(string s) 
{
    return std::stoi(s);
}

#include <stdexcept>
int solution(const std::string& s)
{
    bool IsNegative = false;
	int answer = 0;

	const size_t s_size = s.size();

	if (0 == s_size)
	{
		return 0;
	}

	if ('-' == s[0])
	{
		IsNegative = true;
	}
	else if (true == std::isdigit(s[0]))
	{
		answer = s[0] - '0';
	}
	else
	{
		throw std::runtime_error("Error");
		return 0;
	}

	for (size_t i = 1; i < s_size; i++)
	{
		answer *= 10;
		answer += s[i] - '0';
	}

	return IsNegative ? -answer : answer;
}