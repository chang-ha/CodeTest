#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/17684

using namespace std;

#include <unordered_map>
vector<int> solution(string msg)
{
	vector<int> answer;

	std::unordered_map<std::string, int> Dictionary;
	int Index = 1;
	for (char Input = 'A'; Input <= 'Z'; Input++)
	{
		Dictionary.insert(std::make_pair(std::string(1, Input), Index));
		++Index;
	}

	const std::string::const_iterator EndIter = msg.end();
	const int msg_size = static_cast<int>(msg.size());
	for (int StartIndex = 0; StartIndex < msg_size;)
	{
		std::string::const_iterator StartIter = msg.begin() + StartIndex;
		std::string KeyString = "";
		KeyString += *StartIter;

		while (Dictionary.end() != Dictionary.find(KeyString))
		{
			++StartIter;
			++StartIndex;
			if (EndIter != StartIter)
			{
				KeyString += *StartIter;
			}
			else
			{
				break;
			}
		};

		if (EndIter != StartIter)
		{
			answer.push_back(Dictionary[KeyString.substr(0, KeyString.size() - 1)]);
		}
		else
		{
			answer.push_back(Dictionary[KeyString]);
		}

		Dictionary[KeyString] = Index;
		++Index;
	}

	return answer;
}
