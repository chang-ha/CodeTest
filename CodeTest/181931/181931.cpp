#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) 
{
    int answer = 0;

	size_t Included_Size = included.size();
	for (size_t i = 0; i < Included_Size; i++)
	{
		if (true == included[i])
		{
			answer += a + i * d;
		}
	}

    return answer;
}