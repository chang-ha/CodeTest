#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
	// answer에 체력값 대입
	int answer = health;

	// 에러 체크
	if (3 != bandage.size())
	{
		// Error
		return -1;
	}

	// 이전 공격 시간 계산
	int PrevAttackTime = 0;
	for (const vector<int>& CurAttack : attacks)
	{
		// 에러 체크
		if (2 != CurAttack.size())
		{
			// Error
			return -1;
		}

		// 공격텀 계산
		int DiffAttackTime = CurAttack[0] - PrevAttackTime - 1;

		// 초당 회복량
		int PerHeal = bandage[1] * DiffAttackTime;
		// 연속 회복 성공량
		int ContinuousHeal = (DiffAttackTime / bandage[0]) * bandage[2];
		answer += PerHeal + ContinuousHeal;

		// 최초 health값 이상으로 회복 불가능
		if (health < answer)
		{
			answer = health;
		}

		// 몬스터 공격
		answer -= CurAttack[1];

		// 체력 0 밑이면 -1
		if (0 >= answer)
		{
			return -1;
		}

		// 공격한 시간 계산
		PrevAttackTime = CurAttack[0];
	}

	return answer;
}
