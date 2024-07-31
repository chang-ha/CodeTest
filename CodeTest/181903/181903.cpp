#include <string>
#include <vector>

using namespace std;

string Bettersolution(int q, int r, string code)
{
	string answer = "";

	int Code_Size = static_cast<int>(code.size());
	for (int i = r; i < Code_Size; i += q)
	{
		answer += code[i];
	}

	return answer;
}

string solution(int q, int r, string code)
{
	string answer = "";

	int Code_Size = static_cast<int>(code.size());
	for (int i = 0; i < Code_Size; i++)
	{
		if (r == i % q)
		{
			answer += code[i];
		}
	}

	return answer;
}