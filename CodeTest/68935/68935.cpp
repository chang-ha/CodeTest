#include <string>
#include <vector>

using namespace std;
int Vectorsolution(int n)
{
	int answer = 0;

	std::vector<int> TrinaryDigit;

	while (n != 0)
	{
		TrinaryDigit.push_back(n % 3);
		n /= 3;
	}

	size_t Stack_Size = TrinaryDigit.size();

	for (size_t i = 0; i < Stack_Size; i++)
	{
		answer += TrinaryDigit.back() * static_cast<int>(std::pow(3, i));
		TrinaryDigit.pop_back();
	}

	return answer;
}

#include <stack>
int solution(int n)
{
	int answer = 0;

	std::stack<int> TrinaryDigit;

	while (n != 0)
	{
		TrinaryDigit.push(n % 3);
		n /= 3;
	}

	size_t Stack_Size = TrinaryDigit.size();

	for (size_t i = 0; i < Stack_Size; i++)
	{
		answer += TrinaryDigit.top() * static_cast<int>(std::pow(3, i));
		TrinaryDigit.pop();
	}

	return answer;
}