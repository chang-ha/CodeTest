#include <string>
#include <vector>

using namespace std;

int solution(string number) 
{
    int answer = 0;

	for (const char _CurNumber : number)
	{
		answer += _CurNumber - '0';
	}
	answer %= 9;
    return answer;
}