#include <string>
#include <vector>

using namespace std;

#include <algorithm>
string ssolution(string my_string, vector<int> indices)
{
	string answer = "";

	std::sort(indices.begin(), indices.end());

	const size_t indices_size = indices.size();

	for (size_t i = 0, PrevIndex = 0; i < indices_size; i++)
	{
		answer.append(my_string.begin() + PrevIndex, my_string.begin() + indices[i]);
		PrevIndex = indices[i] + 1;
	}

	answer.append(my_string.begin() + indices.back() + 1, my_string.end());

	return answer;
}