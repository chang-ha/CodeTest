#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/131127

using namespace std;

bool CheckZeroValue(const std::pair<std::string, int>& Pair)
{
	return Pair.second == 0;
}

#include <algorithm>
#include <map>
int solution(vector<string> want, vector<int> number, vector<string> discount)
{
	std::map<std::string, int> DiscountMap;

	const size_t want_size = want.size();
	if (number.size() != want_size)
	{
		return 0;
	}

	for (size_t i = 0; i < want_size; i++)
	{
		DiscountMap[want[i]] = number[i];
	}

	const size_t discount_size = discount.size();
	if (10 > discount_size)
	{
		return 0;
	}

	int answer = 0;
	std::map<std::string, int>::const_iterator EndIter = DiscountMap.end();
	for (size_t i = 0; i < 10; i++)
	{
		if (EndIter == DiscountMap.find(discount[i]))
		{
			continue;
		}

		DiscountMap[discount[i]] -= 1;
		if (true == std::all_of(DiscountMap.begin(), DiscountMap.end(), CheckZeroValue))
		{
			++answer;
		}
	}

	std::string Prevdiscount = "";
	for (size_t i = 10; i < discount_size; i++)
	{
		Prevdiscount = discount[i - 10];
		if (EndIter != DiscountMap.find(Prevdiscount))
		{
			DiscountMap[Prevdiscount] += 1;
		}

		if (EndIter == DiscountMap.find(discount[i]))
		{
			continue;
		}

		DiscountMap[discount[i]] -= 1;

		if (true == std::all_of(DiscountMap.begin(), DiscountMap.end(), CheckZeroValue))
		{
			++answer;
		}
	}

	return answer;
}