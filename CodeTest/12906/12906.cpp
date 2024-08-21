#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer = arr;
	std::vector<int>::iterator LastIter = std::unique(answer.begin(), answer.end());
	answer.erase(LastIter, answer.end());
	return answer;
}