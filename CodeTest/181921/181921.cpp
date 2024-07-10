#include <string>
#include <vector>

using namespace std;

#include <bitset>
vector<int> solution(int l, int r)
{
	vector<int> answer;

	std::vector<int> SubsetVector;

	std::bitset<7> Bit;
	// 1 = 0b1
	// 64 = 0b1'000'000
	for (int i = 1; i <= 64; i++)
	{
		Bit = i;
		int CurValue = std::stoi(Bit.to_string()) * 5;

		if (l > CurValue)
		{
			continue;
		}

		if (r < CurValue)
		{
			break;
		}

		answer.push_back(CurValue);
	}

	if (0 == answer.size())
	{
		answer.push_back(-1);
	}

	return answer;
}