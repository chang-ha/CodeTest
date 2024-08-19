#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int k) 
{
    vector<int> answer;
	answer.reserve(n / k);

	for (int i = k; i <= n; i+= k)
	{
		answer.push_back(i);
	}

    return answer;
}