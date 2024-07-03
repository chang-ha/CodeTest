#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog)
{
	string answer = "";

	size_t Num_Size = numLog.size();
	answer.reserve(Num_Size - 1);

	for (size_t i = 1; i < Num_Size; i++)
	{
		int SubNum = numLog[i] - numLog[i - 1];
		switch (SubNum)
		{
		case 1:
			answer += 'w';
			break;
		case -1:
			answer += 's';
			break;
		case 10:
			answer += 'd';
			break;
		case -10:
			answer += 'a';
			break;
		default:
			break;
		}
	}

	return answer;
}