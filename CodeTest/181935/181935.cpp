#include <string>
#include <vector>

using namespace std;
#include <cmath>

int solution(int n)
{
	int answer = 0;
	int LoopCount = n / 2;
	switch (n % 2)
	{
	case 0:
	{
		// Even
		for (int i = 1; i <= LoopCount; i++)
		{
			answer += std::pow(i * 2, 2);
		}
		break;
	}
	case 1:
	{
		// Odd
		for (int i = 0; i <= LoopCount; i++)
		{
			answer += i * 2 + 1;
		}
		break;
	}
	default:
		// Error
		break;
	}
	return answer;
}