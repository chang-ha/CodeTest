#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/42578

using namespace std;

#include <unordered_map>
#include <stdexcept>
int solution(vector<vector<string>> clothes)
{
	std::unordered_map<std::string, int> Cloth_map;

	for (const std::vector<std::string>& CurCloth : clothes)
	{
		if (2 != CurCloth.size())
		{
			// Error
			// throw std::invalid_argument("Cloth Vector size must be 2");
			return -1;
		}

		const std::string cloth_type = CurCloth[1];
		Cloth_map[cloth_type] += 1;
	}

	size_t answer = 1;
	for (const std::pair<std::string, int>& CurPair : Cloth_map)
	{
		answer *= CurPair.second + 1;
	}
	// https://school.programmers.co.kr/questions/33347
	answer -= 1; // 모든 걸 안입는 경우 제외

	return static_cast<int>(answer);
}

// 옷 이름 보고싶을 떄 list 사용
#include <list>
int solution(vector<vector<string>> clothes)
{
	std::unordered_map<std::string, std::list<std::string>> Cloth_map;

	for (const std::vector<std::string>& CurCloth : clothes)
	{
		if (2 != CurCloth.size())
		{
			// Error
			// throw std::invalid_argument("Cloth Vector size must be 2");
			return -1;
		}

		const std::string cloth_type = CurCloth[1];
		const std::string cloth_name = CurCloth[0];

		std::unordered_map<std::string, std::list<std::string>>::iterator FindIter = Cloth_map.find(cloth_type);
		if (Cloth_map.end() != FindIter)
		{
			FindIter->second.push_back(cloth_name);
		}
		else
		{
			std::list<std::string> clothVector = { cloth_name };
			Cloth_map.insert(std::make_pair(cloth_type, clothVector));
		}
	}

	size_t answer = 1;
	for (const std::pair<std::string, std::list<std::string>>& CurPair : Cloth_map)
	{
		answer *= CurPair.second.size() + 1;
	}
	answer -= 1; // 모든 걸 안입는 경우 제외

	return static_cast<int>(answer);
}