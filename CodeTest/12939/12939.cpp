#include <string>
#include <vector>

using namespace std;

#include <limits.h>
string solution(string s)
{
	s += ' ';

	int MinValue = INT_MAX;
	int MaxValue = INT_MIN;
	size_t PrevPos = 0;
	size_t DividePos = s.find(' ');
	while (std::string::npos != DividePos)
	{
		int CurValue = std::stoi(s.substr(PrevPos, DividePos));

		MinValue = std::min(MinValue, CurValue);
		MaxValue = std::max(MaxValue, CurValue);
		PrevPos = DividePos + 1;
		DividePos = s.find(' ', PrevPos);
	}

	std::string answer = std::to_string(MinValue) + ' ' + std::to_string(MaxValue);
	return answer;
}

#include <sstream>
string sstreamsolution(string s)
{
	std::stringstream s_stream(s);

	int MinValue = INT_MAX;
	int MaxValue = INT_MIN;
	int Value = 0;
	while (s_stream >> Value)
	{
		MinValue = std::min(MinValue, Value);
		MaxValue = std::max(MaxValue, Value);
	}

	std::string answer = std::to_string(MinValue) + ' ' + std::to_string(MaxValue);
	return answer;
}