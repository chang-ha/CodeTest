#include <string>
#include <vector>
#include <set>

using namespace std;

// C++ 17 이상 extract && Node_handle
// 키나 데이터를 복사 or 이동하는데 따른 오버헤드를 발생시키지 않기 위한 함수 및 클래스
vector<int> Extractsolution(int k, vector<int> score)
{
	vector<int> answer;
	answer.reserve(score.size());

	std::multiset<int> ScoreBoard;

	for (const int _CurScore : score)
	{
		if (k > ScoreBoard.size())
		{
			ScoreBoard.insert(_CurScore);
		}
		else if (_CurScore > *ScoreBoard.begin())
		{
			std::_Node_handle CurNode = ScoreBoard.extract(ScoreBoard.begin());
			CurNode.value() = _CurScore;
			ScoreBoard.insert(std::move(CurNode));
		}
		answer.push_back(*ScoreBoard.begin());
	}

	return answer;
}

vector<int> Erasesolution(int k, vector<int> score)
{
	vector<int> answer;
	answer.reserve(score.size());

	std::multiset<int> ScoreBoard;

	for (const int _CurScore : score)
	{
		if (k > ScoreBoard.size())
		{
			ScoreBoard.insert(_CurScore);
		}
		else if (_CurScore > *ScoreBoard.begin())
		{
			ScoreBoard.erase(ScoreBoard.begin());
			ScoreBoard.insert(_CurScore);
		}
		answer.push_back(*ScoreBoard.begin());
	}

	return answer;
}

// 다른사람 풀이
// 느림
#include <algorithm>
vector<int> Otherssolution(int k, vector<int> score) {
	vector<int> answer, tmp;

	for (auto s : score) {
		tmp.push_back(s);
		std::sort(tmp.begin(), tmp.end(), greater<int>());
		if (tmp.size() >= k) tmp.erase(tmp.begin() + k, tmp.end());
		answer.push_back(tmp.back());
	}

	return answer;

}