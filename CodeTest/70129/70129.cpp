#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/70129

using namespace std;

#include <algorithm>
#include <numeric>
vector<int> Vectorsolution(string s)
{
	vector<int> answer(2, 0);
	std::vector<int> Bitset(s.size(), false);
	std::transform(s.begin(), s.end(), Bitset.begin(), [](const char CurChar)
		{
			return '1' == CurChar;
		});

	while (1 != Bitset.size())
	{
		int OneCount = std::accumulate(Bitset.begin(), Bitset.end(), 0);
		int ZeroCount = static_cast<int>(Bitset.size()) - OneCount;
		answer[0] += 1;
		answer[1] += ZeroCount;
		Bitset.clear();

		while (0 != OneCount)
		{
			Bitset.push_back(OneCount % 2);
			OneCount /= 2;
		}
	}

	return answer;
}


#include <stdexcept>
vector<int> solution(string s)
{
	vector<int> answer(2, 0);

	int ZeroCount = 0;
	int OneCount = 0;
	while ("1" != s)
	{
		for (const char CurChar : s)
		{
			switch (CurChar)
			{
			case '0':
				++ZeroCount;
				break;
			case '1':
				++OneCount;
				break;
			default:
				throw std::invalid_argument("argument must be 0 or 1");
			}
		}

		s.clear();
		while (0 != OneCount)
		{
			s += std::to_string((OneCount % 2));
			OneCount /= 2;
		}

		answer[0] += 1;
		answer[1] += ZeroCount;
		ZeroCount = 0;
	}

	return answer;
}