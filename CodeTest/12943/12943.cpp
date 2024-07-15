#include <string>
#include <vector>

// if - else 와 ternary operator 간 차이 거의 X
using namespace std;
int solution(int num)
{
	int answer = 0;
	long long lnum = static_cast<long long>(num);
	while (lnum != 1)
	{
		if (500 == answer)
		{
			answer = -1;
			break;
		}

		if (lnum % 2 == 0)
		{
			lnum /= 2;
		}
		else
		{
			lnum = 3 * lnum + 1;
		}
		++answer;
	}
	return answer;
}

int Thridoperatorsolution(int num)
{
	int answer = 0;
	long long lnum = static_cast<long long>(num);
	while (lnum != 1)
	{
		if (500 == answer)
		{
			answer = -1;
			break;
		}

		lnum = lnum % 2 == 0 ? lnum / 2 : lnum * 3 + 1;
		++answer;
	}
	return answer;
}