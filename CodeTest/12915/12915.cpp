#include <string>
#include <vector>

using namespace std;

#include <stdexcept>
#include <algorithm>
vector<string> solution(vector<string> strings, int n)
{
	vector<string> answer(strings.begin(), strings.end());

	std::sort(answer.begin(), answer.end(), [sortIndex = n](const std::string& _A, const std::string& _B)
		{
			char A_Char = ' ';
			char B_Char = ' ';
			try
			{
				A_Char = _A.at(sortIndex);
			}
			catch (const std::out_of_range&)
			{
				throw std::runtime_error("Index가 A_string의 범위를 벗어났습니다.");
			}

			try
			{
				B_Char = _B.at(sortIndex);
			}
			catch (const std::out_of_range&)
			{
				throw std::runtime_error("Index가 B_string의 범위를 벗어났습니다.");
			}

			return A_Char == B_Char ? _A < _B : A_Char < B_Char;
		});

	return answer;
}