#include <string>
#include <vector>

using namespace std;

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