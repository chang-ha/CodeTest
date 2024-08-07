#include <string>
#include <vector>

using namespace std;

#include <unordered_map>
int usolution(string s)
{
	std::string StringAnswer = "";

	// string과 char 맵핑
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
		// 현재 char가 숫자인지 판단
		if (0 != std::isdigit(*StartIter))
		{
			StringAnswer += *StartIter;
			++StartIter;
			continue;
		}

		std::string NumberString = "";
		int StringLength = 0;

		// 1, 2번째 글자에 따라 길이 판단
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

		// 글자 길이 만큼 NumberString에 저장
		NumberString.append(StartIter, StartIter + StringLength);
		// 글자 길이 만큼 이동
		StartIter += StringLength;

		// NumberString이 맵핑한 값이 있는지 판단
		if (NumberMap.end() != NumberMap.find(NumberString))
		{
			// 맵핑되는 char값 추가
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
	s = regex_replace(s, regex("zero"), "0"); // string 에서 "zero" 를 전부 찾아서 "0" 으로 치환
	s = regex_replace(s, regex("one"), "1"); // 위와 동일 ...
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