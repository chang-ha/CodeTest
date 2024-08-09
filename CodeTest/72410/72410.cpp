#include <string>
#include <vector>

#include <algorithm>
std::string solution(std::string new_id)
{
	std::string answer = "";
	answer.resize(new_id.size());
	std::transform(new_id.begin(), new_id.end(), answer.begin(), ::tolower);

	std::string CalcuString = "";
	for (const char _CurChar : answer)
	{
		if (('a' <= _CurChar && 'z' >= _CurChar) ||
			('0' <= _CurChar && '9' >= _CurChar) ||
			'.' == _CurChar || '-' == _CurChar || '_' == _CurChar)
		{
			CalcuString += _CurChar;
		}
	}
	answer = CalcuString;
	CalcuString.clear();

	for (const char _CurChar : answer)
	{
		if ('.' == _CurChar &&
			(true == CalcuString.empty() || '.' == CalcuString.back()))
		{
			continue;
		}
		CalcuString += _CurChar;
	}
	answer = CalcuString;

	if ('.' == answer.back())
	{
		answer.pop_back();
	}

	size_t Answer_Size = answer.size();
	if (0 == Answer_Size)
	{
		answer = "aaa";
	}
	else if (16 <= Answer_Size)
	{
		answer = answer.substr(0, 15);
		if ('.' == answer.back())
		{
			answer.pop_back();
		}
	}
	else if (2 >= Answer_Size)
	{
		while (3 > answer.size())
		{
			answer += answer.back();
		}
	}

	return answer;
}

#include <regex>
// std::tolower -> 로컬에 따른 문자열 변환 -> wchar_t a = std::toupper(L'\u0190', std::locale()); or US지역 문자 변환 : std::locale("en_US.utf8")
std::string Regexsolution(std::string new_id)
{
	std::string answer = "";
	answer.resize(new_id.size());
	std::transform(new_id.begin(), new_id.end(), answer.begin(), ::tolower);
	std::regex SecondStep("[^a-z0-9._-]");
	answer = std::regex_replace(answer, SecondStep, "");

	std::regex ThirdStep("[.]{1,}");
	answer = std::regex_replace(answer, ThirdStep, ".");

	std::regex FourthStep("^[.]|[.]$");
	answer = std::regex_replace(answer, FourthStep, "");

	size_t Answer_Size = answer.size();
	if (0 == Answer_Size)
	{
		answer = "aaa";
	}
	else if (16 <= Answer_Size)
	{
		std::regex SixthStep("[.]$");
		answer = answer.substr(0, 15);
		answer = std::regex_replace(answer, SixthStep, "");
	}
	else if (2 >= Answer_Size)
	{
		while (3 > answer.size())
		{
			answer += answer.back();
		}
	}

	return answer;
}