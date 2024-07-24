#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) 
{
    vector<int> answer;
	answer.reserve(intStrs.size());

	for (const std::string& _CurIntStr : intStrs)
	{
		int _CurInt = std::stoi(_CurIntStr.substr(s, l));

		if (k < _CurInt)
		{
			answer.push_back(_CurInt);
		}
	}

    return answer;
}