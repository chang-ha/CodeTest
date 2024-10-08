#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/155651

using namespace std;

int CalcuTime(const std::string& _Time)
{
	if (5 != _Time.size())
	{
		return -1;
	}

	const size_t Pos = _Time.find_first_of(':');

	const int Hour = std::stoi(_Time.substr(0, Pos));
	const int Minute = std::stoi(_Time.substr(Pos + 1));

	return Hour * 60 + Minute;
}

struct compare_pair
{
	bool operator()(const std::pair<int, int> _First, const std::pair<int, int> _Second) const
	{
		return _First.second > _Second.second;
	}
};


#include <algorithm>
#include <queue>
int solution(vector<vector<string>> book_time)
{
	int answer = 0;

	// 입실 시간이 빠른 순으로 정렬
	std::sort(book_time.begin(), book_time.end(), [](const std::vector<string>& _First, const std::vector<string>& _Second)
		{
			return _First[0] < _Second[0];
		});

	// 퇴실 시간이 빠른 순으로 우선순위
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare_pair> book_room;

	for (const std::vector<std::string>& _CurBookTime : book_time)
	{
		const int CurTime = CalcuTime(_CurBookTime[0]);
		while (false == book_room.empty())
		{
			// 현재 시간 기준으로 퇴실 가능한 방 제외
			if (CurTime >= book_room.top().second + 10)
			{
				book_room.pop();
			}
			else
			{
				break;
			}
		}

		book_room.emplace(CurTime, CalcuTime(_CurBookTime[1]));
		answer = std::max(answer, static_cast<int>(book_room.size()));
	}

	return answer;
}