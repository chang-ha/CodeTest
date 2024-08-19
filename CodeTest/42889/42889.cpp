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

	// 1 -> stages[i] 값이 1인 수 / stages[i] 값이 1보다 크거나 같은 수

	// 전체 유저수 계산
	int UserCount = static_cast<int>(stages.size());
	for (const int _CurStage : stages)
	{
		// N번째 유저가 도달한 스테이지 번호 (N+1은 끝까지 클리어)
		StageUserCount[_CurStage] += 1;
	}

	// 실패율과 해당 스테이지 매핑(set으로 내부 정렬)
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
		// i 스테이지에 막힌 유저 수 / i 스테이지에 도달한 유저 수 (전체 유저 - 이전 스테이지에 막힌 유저 수)
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
