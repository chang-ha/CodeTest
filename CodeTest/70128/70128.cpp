#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) 
{
	size_t A_Size = a.size();
	if (b.size() != A_Size)
	{
		return -1;
	}

    int answer = 0;

	for (size_t i = 0; i < A_Size; i++)
	{
		answer += a[i] * b[i];
	}

	// inner_product(a.begin(),a.end(),b.begin(),0);
	// https://programmerpsy.tistory.com/50

    return answer;
}