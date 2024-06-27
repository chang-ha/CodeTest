#include <string>
#include <vector>

using namespace std;

string solution(string code)
{
	string answer = "";

	size_t Code_Size = code.size();
	int Mode = 0;

	for (size_t i = 0; i < Code_Size; i++)
	{
		if ('1' == code[i])
		{
			Mode = std::abs(Mode - 1);
			continue;
		}

		if (Mode == i % 2)
		{
			answer += code[i];
		}
	}

	if ("" == answer)
	{
		answer = "EMPTY";
	}

	return answer;
}
