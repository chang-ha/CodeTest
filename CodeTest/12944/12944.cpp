#include <string>
#include <vector>

using namespace std;
double solution(vector<int> arr)
{
	double answer = 0;
	long long Sum = 0;

	for (const int _CurValue : arr)
	{
		Sum += _CurValue;
	}

	answer = static_cast<double>(Sum) / arr.size();

	return answer;
}

#include <numeric>
double STLsolution(vector<int> arr)
{
	double answer = std::accumulate(arr.begin(), arr.end(), 0);

	return answer / arr.size();
}
