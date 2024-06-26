#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) 
{
    int answer = 0;
	switch (flag)
	{
	case true:
		answer = a + b;
		break;
	case false:
		answer = a - b;
		break;
	default:
		// Error
		break;
	}
    return answer;
}
