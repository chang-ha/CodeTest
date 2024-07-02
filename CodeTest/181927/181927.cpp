#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list)
{
	size_t Num_Size = num_list.size();
	int LastNum = num_list[Num_Size - 1];
	int LastPrevNum = num_list[Num_Size - 2];

	num_list.push_back(LastNum > LastPrevNum ? LastNum - LastPrevNum : LastNum * 2);

	return num_list;
}