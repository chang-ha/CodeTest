#include <string>
#include <vector>

using namespace std;

#include <unordered_map>
int usolution(string s)
{
	std::string StringAnswer = "";
	std::unordered_map<std::string, char> NumberMap = {
		{"zero", '0'},
		{"one", '1'},
		{"two", '2'} ,
		{"three", '3'} ,
		{"four", '4'} ,
		{"five", '5'} ,
		{"six", '6'} ,
		{"seven", '7'} ,
		{"eight", '8'} ,
		{"nine", '9'} };

	std::string::const_iterator StartIter = s.begin();
	std::string::const_iterator EndIter = s.end();

	for (; StartIter != EndIter;)
	{
		if (0 != std::isdigit(*StartIter))
		{
			StringAnswer += *StartIter;
			++StartIter;
			continue;
		}

		std::string NumberString = "";
		int StringLength = 0;

		switch (*StartIter)
		{
		case 'z':
			// zero
			StringLength = 4;
			break;
		case 'o':
			// one
			StringLength = 3;
			break;
		case 't':
			// two three
		{
			std::string::const_iterator SecondIter = StartIter + 1;
			switch (*SecondIter)
			{
			case 'w':
				StringLength = 3;
				break;
			case 'h':
				StringLength = 5;
				break;
			default:
				return -1;
				break;
			}
			break;
		}
		case 'f':
			// four five
			StringLength = 4;
			break;
		case 's':
			// six seven
		{
			std::string::const_iterator SecondIter = StartIter + 1;
			switch (*SecondIter)
			{
			case 'i':
				StringLength = 3;
				break;
			case 'e':
				StringLength = 5;
				break;
			default:
				return -1;
				break;
			}
			break;
		}
		case 'e':
			// eight
			StringLength = 5;
			break;
		case 'n':
			// nine
			StringLength = 4;
			break;
		default:
			// Error
			return -1;
			break;
		}

		NumberString.append(StartIter, StartIter + StringLength);
		StartIter += StringLength;

		if (NumberMap.end() != NumberMap.find(NumberString))
		{
			StringAnswer += NumberMap[NumberString];
		}
	}

	return std::stoi(StringAnswer);
}

#include <map>
int solution(string s)
{
	std::string StringAnswer = "";
	std::map<std::string, char> NumberMap = {
		{"zero", '0'},
		{"one", '1'},
		{"two", '2'} ,
		{"three", '3'} ,
		{"four", '4'} ,
		{"five", '5'} ,
		{"six", '6'} ,
		{"seven", '7'} ,
		{"eight", '8'} ,
		{"nine", '9'} };

	std::string::const_iterator StartIter = s.begin();
	std::string::const_iterator EndIter = s.end();

	for (; StartIter != EndIter;)
	{
		if (0 != std::isdigit(*StartIter))
		{
			StringAnswer += *StartIter;
			++StartIter;
			continue;
		}

		std::string NumberString = "";
		int StringLength = 0;

		switch (*StartIter)
		{
		case 'z':
			// zero
			StringLength = 4;
			break;
		case 'o':
			// one
			StringLength = 3;
			break;
		case 't':
			// two three
		{
			std::string::const_iterator SecondIter = StartIter + 1;
			switch (*SecondIter)
			{
			case 'w':
				StringLength = 3;
				break;
			case 'h':
				StringLength = 5;
				break;
			default:
				return -1;
				break;
			}
			break;
		}
		case 'f':
			// four five
			StringLength = 4;
			break;
		case 's':
			// six seven
		{
			std::string::const_iterator SecondIter = StartIter + 1;
			switch (*SecondIter)
			{
			case 'i':
				StringLength = 3;
				break;
			case 'e':
				StringLength = 5;
				break;
			default:
				return -1;
				break;
			}
			break;
		}
		case 'e':
			// eight
			StringLength = 5;
			break;
		case 'n':
			// nine
			StringLength = 4;
			break;
		default:
			// Error
			return -1;
			break;
		}

		NumberString.append(StartIter, StartIter + StringLength);
		StartIter += StringLength;

		if (NumberMap.end() != NumberMap.find(NumberString))
		{
			StringAnswer += NumberMap[NumberString];
		}
	}

	return std::stoi(StringAnswer);
}

// 정규표현식은 느림
// "onetwothreefourfivesixseveneightnine"
// 약 8배 차이남
#include <regex>
int Regexsolution(string s) {
	s = regex_replace(s, regex("zero"), "0");
	s = regex_replace(s, regex("one"), "1");
	s = regex_replace(s, regex("two"), "2");
	s = regex_replace(s, regex("three"), "3");
	s = regex_replace(s, regex("four"), "4");
	s = regex_replace(s, regex("five"), "5");
	s = regex_replace(s, regex("six"), "6");
	s = regex_replace(s, regex("seven"), "7");
	s = regex_replace(s, regex("eight"), "8");
	s = regex_replace(s, regex("nine"), "9");
	return stoi(s);
}