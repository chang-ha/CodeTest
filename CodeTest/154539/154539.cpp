#include <string>
#include <vector>

// ¹®Á¦ 
// https://school.programmers.co.kr/learn/courses/30/lessons/154539

using namespace std;

#include <stack>
vector<int> solution(vector<int> numbers)
{
	const int numbers_size = static_cast<int>(numbers.size());
	vector<int> answer(numbers_size, -1);

	std::stack<int> numberStack;
	for (int i = numbers_size - 1; i >= 0; i--)
	{
		while (false == numberStack.empty())
		{
			const int CurValue = numberStack.top();
			if (numbers[i] < CurValue)
			{
				answer[i] = CurValue;
				break;
			}
			numberStack.pop();
		}
		numberStack.push(numbers[i]);
	}

	return answer;
}