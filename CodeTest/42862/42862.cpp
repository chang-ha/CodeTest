#include <string>
#include <vector>

using namespace std;

#include <algorithm>
int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = static_cast<int>(reserve.size());

	std::sort(lost.begin(), lost.end());
	std::sort(reserve.begin(), reserve.end());

	int PrevIndex = 0;
	for (const int _BorrowPeople : lost)
	{
		int LendPeople = reserve[PrevIndex];
		if (LendPeople - 1 == _BorrowPeople ||
			LendPeople + 1 == _BorrowPeople)
		{
			++answer;
			++PrevIndex;
		}
	}

    return answer;
}