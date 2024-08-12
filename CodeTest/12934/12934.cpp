#include <string>
#include <vector>

using namespace std;

#include <cmath>
long long solution(long long n) {
	long long answer = 0;

	double n_sqrt = std::sqrt(n);

	if (std::floor(n_sqrt) == std::ceil(n_sqrt))
	{
		double answer_sqrt = n_sqrt + 1;
		answer = static_cast<long long>(answer_sqrt * answer_sqrt);
	}
	else
	{
		answer = -1;
	}

	return answer;
}