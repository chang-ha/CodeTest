#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
	// answer�� ü�°� ����
	int answer = health;

	// ���� üũ
	if (3 != bandage.size())
	{
		// Error
		return -1;
	}

	// ���� ���� �ð� ���
	int PrevAttackTime = 0;
	for (const vector<int>& CurAttack : attacks)
	{
		// ���� üũ
		if (2 != CurAttack.size())
		{
			// Error
			return -1;
		}

		// ������ ���
		int DiffAttackTime = CurAttack[0] - PrevAttackTime - 1;

		// �ʴ� ȸ����
		int PerHeal = bandage[1] * DiffAttackTime;
		// ���� ȸ�� ������
		int ContinuousHeal = (DiffAttackTime / bandage[0]) * bandage[2];
		answer += PerHeal + ContinuousHeal;

		// ���� health�� �̻����� ȸ�� �Ұ���
		if (health < answer)
		{
			answer = health;
		}

		// ���� ����
		answer -= CurAttack[1];

		// ü�� 0 ���̸� -1
		if (0 >= answer)
		{
			return -1;
		}

		// ������ �ð� ���
		PrevAttackTime = CurAttack[0];
	}

	return answer;
}
