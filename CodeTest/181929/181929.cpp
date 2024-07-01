#include <string>
#include <vector>

using namespace std;

#include <cmath>
int Multisolution(vector<int> num_list)
{
	int answer = 0;

	int Multi = 1;
	int Sum = 0;

	for (const int _CurNum : num_list)
	{
		Multi *= _CurNum;
		Sum += _CurNum;
	}

	answer = Multi > Sum * Sum ? 0 : 1;

	return answer;
}

int Powsolution(vector<int> num_list)
{
	int answer = 0;

	int Multi = 1;
	int Sum = 0;

	for (const int _CurNum : num_list)
	{
		Multi *= _CurNum;
		Sum += _CurNum;
	}

	answer = Multi > std::pow(Sum, 2) ? 0 : 1;

	return answer;
}

#include <numeric>
int Accumulatesolution(vector<int> num_list) {
	return accumulate(num_list.begin(), num_list.end(), 1, multiplies<int>()) < pow(accumulate(num_list.begin(), num_list.end(), 0), 2) ? 1 : 0;
}