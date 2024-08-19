#include <string>
#include <vector>

using namespace std;
#include <map>
#include <set>

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	answer.reserve(N);

	std::vector<int> StageUserCount(N + 2, 0);

	// 1 -> stages[i] ���� 1�� �� / stages[i] ���� 1���� ũ�ų� ���� ��

	// ��ü ������ ���
	int UserCount = static_cast<int>(stages.size());
	for (const int _CurStage : stages)
	{
		// N��° ������ ������ �������� ��ȣ (N+1�� ������ Ŭ����)
		StageUserCount[_CurStage] += 1;
	}

	// �������� �ش� �������� ����(set���� ���� ����)
	std::map<float, std::set<int>> FailRatio;

	for (int i = 1; i <= N; i++)
	{
		int PrevStage = i - 1;

		if (0 > PrevStage || N <= PrevStage)
		{
			// Error
			return { -1, };
		}

		UserCount -= StageUserCount[PrevStage];
		// i ���������� ���� ���� �� / i ���������� ������ ���� �� (��ü ���� - ���� ���������� ���� ���� ��)
		float StageFailRatio = 0.f;
		if (0 < UserCount)
		{
			StageFailRatio = static_cast<float>(StageUserCount[i]) / UserCount;
		}

		FailRatio[StageFailRatio].insert(i);
	}

	std::map<float, std::set<int>>::const_reverse_iterator StartIter = FailRatio.rbegin();
	std::map<float, std::set<int>>::const_reverse_iterator EndIter = FailRatio.rend();

	for (; StartIter != EndIter; ++StartIter)
	{
		std::set<int>::const_iterator SetStartIter = StartIter->second.begin();
		std::set<int>::const_iterator SetEndIter = StartIter->second.end();
		for (; SetStartIter != SetEndIter; ++SetStartIter)
		{
			answer.push_back(*SetStartIter);
		}
	}

	return answer;
}
