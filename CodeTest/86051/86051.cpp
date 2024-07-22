#include <string>
#include <vector>
using namespace std;

int solution(vector<int> numbers)
{
	int answer = 45; // sum of 0 ~ 9

	for (const int _CurValue : numbers)
	{
		answer -= _CurValue;
	}

	return answer;
}
