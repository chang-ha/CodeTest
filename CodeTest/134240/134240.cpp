#include <string>
#include <vector>

using namespace std;

#include <algorithm>
string solution(vector<int> food)
{
	string answer = "";
	string Reverse_answer = "";

	if (1 > food[0])
	{
		// ���� 1�� �̻� �����ؾ���
		return answer;
	}

	int Food_Size = static_cast<int>(food.size());

	for (int i = 1; i < Food_Size; i++)
	{
		// 1 -> 4��
		// string 2���� 2����
		int AppendCount = food[i] / 2;
		int AppendChar = '0' + i;
		answer.append(AppendCount, AppendChar);
		Reverse_answer.append(AppendCount, AppendChar);
	}

	answer.push_back('0');
	std::reverse(Reverse_answer.begin(), Reverse_answer.end());
	answer.append(Reverse_answer);

	return answer;
}

string movesolution(vector<int> food)
{
	string answer = "";
	string Reverse_answer = "";

	if (1 > food[0])
	{
		// ���� 1�� �̻� �����ؾ���
		return answer;
	}

	int Food_Size = static_cast<int>(food.size());

	for (int i = 1; i < Food_Size; i++)
	{
		int AppendCount = food[i] / 2;
		int AppendChar = '0' + i;
		answer.append(AppendCount, AppendChar);
		Reverse_answer.append(AppendCount, AppendChar);
	}

	answer.push_back('0');
	std::reverse(Reverse_answer.begin(), Reverse_answer.end());
	answer.append(std::move(Reverse_answer));

	return answer;
}