#include <string>
#include <vector>

using namespace std;

#include <algorithm>
#include <stdexcept>
vector<int> solution(vector<int> numbers)
{
	const long long numbers_size = static_cast<long long>(numbers.size());

	if (1 >= numbers_size)
	{
		throw std::runtime_error("numbers의 갯수가 부족합니다.");
		return vector<int>(-1, 1);
	}

	vector<int> answer;
	// 중복없는 최대 갯수
	answer.reserve(numbers_size * (numbers_size - 1) / 2);

	for (int i = 0; i < numbers_size; i++)
	{
		for (int j = i + 1; j < numbers_size; j++)
		{
			answer.push_back(numbers[i] + numbers[j]);
		}
	}

	std::sort(answer.begin(), answer.end());
	answer.erase(std::unique(answer.begin(), answer.end()), answer.end());
	return answer;
}

// set 활용시 sort, unique 필요없지만
// vector보다 느림
#include <set>
vector<int> Setsolution(vector<int> numbers)
{
	const int numbers_size = static_cast<int>(numbers.size());

	if (1 >= numbers_size)
	{
		throw std::runtime_error("numbers의 갯수가 부족합니다.");
		return vector<int>(-1, 1);
	}

	std::set<int> CalcuSet;

	for (int i = 0; i < numbers_size; i++)
	{
		for (int j = i + 1; j < numbers_size; j++)
		{
			CalcuSet.insert(numbers[i] + numbers[j]);
		}
	}

	vector<int> answer(CalcuSet.begin(), CalcuSet.end());

	return answer;
}
