#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/17680

using namespace std;

#include <list>
#include <algorithm>
int listsolution(int cacheSize, vector<string> cities)
{
	if (0 == cacheSize)
	{
		return static_cast<int>(cities.size()) * 5;
	}

	int answer = 0;
	std::list<std::string> cache_list;

	for (std::string& Curcity : cities)
	{
		std::transform(Curcity.begin(), Curcity.end(), Curcity.begin(), ::tolower);
		std::list<std::string>::iterator FindIter = std::find(cache_list.begin(), cache_list.end(), Curcity);

		cache_list.push_back(Curcity);
		if (cache_list.end() != FindIter)
		{
			++answer;
			cache_list.erase(FindIter);
			continue;
		}

		if (cacheSize < cache_list.size())
		{
			cache_list.pop_front();
		}
		answer += 5;
	}

	return answer;
}

// u_map이 1.5배 이상 느림
#include <unordered_map>
int hashsolution(int cacheSize, vector<string> cities)
{
	if (0 == cacheSize)
	{
		return static_cast<int>(cities.size()) * 5;
	}

	int answer = 0;
	std::unordered_map<std::string, int> city_map;

	for (std::string& Curcity : cities)
	{
		std::transform(Curcity.begin(), Curcity.end(), Curcity.begin(), ::tolower);
		if (city_map.end() != city_map.find(Curcity))
		{
			++answer;
			continue;
		}

		answer += 5;
		city_map[Curcity] = 0;

		for (std::pair<const std::string, int>& Curpair : city_map)
		{
			Curpair.second += 1;
		}

		if (cacheSize >= city_map.size())
		{
			continue;
		}

		std::unordered_map<std::string, int>::iterator FindIter = std::max_element(city_map.begin(), city_map.end(), [](const auto& First, const auto& Second)
			{
				return First.second < Second.second;
			});

		city_map.erase(FindIter);
	}

	return answer;
}