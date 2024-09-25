#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/131130

using namespace std;

#include <list>
#include <algorithm>
int solution(vector<int> cards)
{
	int answer = 0;

	const int cards_size = static_cast<int>(cards.size());
	std::vector<bool> Open_Box(cards_size);
	std::vector<int> GroupSize_vector;
	GroupSize_vector.reserve(cards_size);

	std::list<int> SameGroup;
	for (int i = 0; i < cards_size; i++)
	{
		while (false == Open_Box[i])
		{
			SameGroup.push_back(i);
			Open_Box[i] = true;
			i = cards[i] - 1;
		}
		GroupSize_vector.push_back(static_cast<int>(SameGroup.size()));
		SameGroup.clear();
	}

	if (1 >= GroupSize_vector.size())
	{
		return 0;
	}

	std::sort(GroupSize_vector.begin(), GroupSize_vector.end(), greater<int>());

	return GroupSize_vector[0] * GroupSize_vector[1];
}