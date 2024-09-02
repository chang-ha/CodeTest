#include <string>
#include <vector>

using namespace std;

#include <stdexcept>
vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> answer;
	answer.reserve(n);

	if (n != static_cast<int>(arr1.size()) ||
		n != static_cast<int>(arr2.size()))
	{
		// Error
		throw std::runtime_error("지도의 크기가 옳바르지 않습니다.");
		return answer;
	}

	for (int i = 0; i < n; i++)
	{
		std::string Map = "";
		int FindWall = arr1[i] | arr2[i];

		for (int j = n - 1; j >= 0; j--)
		{
			bool IsWall = (FindWall >> j) & 0x1;
			if (true == IsWall)
			{
				Map += '#';
			}
			else
			{
				Map += ' ';
			}
		}

		answer.push_back(Map);
	}

	return answer;
}
