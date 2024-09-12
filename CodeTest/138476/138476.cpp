#include <string>
#include <vector>

using namespace std;

#include <map>
int solution(int k, vector<int> tangerine)
{
	int answer = 0;

	std::map<int, int> type_tangerine;

	for (const int Curtangerine : tangerine)
	{
		type_tangerine[Curtangerine] += 1;
	}

	std::map<int, int, greater<int>> count_tangerine;
	for (const std::pair<int, int>& Curtangerine : type_tangerine)
	{
		count_tangerine[Curtangerine.second] += 1;
	}

	for (const std::pair<int, int>& Curtangerine : count_tangerine)
	{
		for (size_t i = 0; i < Curtangerine.second; ++i)
		{
			k -= Curtangerine.first;
			++answer;
			if (0 >= k)
			{
				return answer;
			}
		}
	}

	return answer;
}

// 귤의 input 종류의 값이 작을수록 빠르지만
// 귤의 input값이 차이가 심할수록 느려짐  == counting star의 단점
// ex)	std::vector<int> InputVector = { 1,3,2,5,4,5,2,3,1000,502,11111,30291,1,2,3321,222,69201 };
// Map보다 현저히 느려짐
#include <algorithm>
int Vectorsolution(int k, vector<int> tangerine)
{
	int answer = 0;
	int MaxValue = *std::max_element(tangerine.begin(), tangerine.end());
	std::vector<int> CountingStar(MaxValue, 0);

	for (const int Curtangerine : tangerine)
	{
		CountingStar[Curtangerine - 1] += 1;
	}

	std::sort(CountingStar.begin(), CountingStar.end(), greater<int>());

	for (const int CurCount : CountingStar)
	{
		k -= CurCount;
		++answer;
		if (0 >= k)
		{
			break;
		}
	}

	return answer;
}