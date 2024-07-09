#include <string>
#include <vector>

using namespace std;

vector<int> Constsolution(vector<int> arr, vector<vector<int>> queries)
{
	vector<int> answer = arr;

	for (const vector<int>& _CurQuery : queries)
	{
		std::swap(answer.at(_CurQuery[0]), answer.at(_CurQuery[1]));
	}

	return answer;
}

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
	vector<int> answer = arr;

	for (vector<int> _CurQuery : queries)
	{
		std::swap(answer.at(_CurQuery[0]), answer.at(_CurQuery[1]));
	}

	return answer;
}