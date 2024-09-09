#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/176962

using namespace std;

int CalcuTime(const std::string& _Time)
{
	size_t DividePos = _Time.find_first_of(":");

	if (std::string::npos == DividePos)
	{
		// Error
		return -1;
	}

	int Hour = std::stoi(_Time.substr(0, DividePos));
	int Minute = std::stoi(_Time.substr(DividePos + 1));

	return Hour * 60 + Minute;
}

#include <stack>
#include <tuple>
#include <algorithm>
vector<string> solution(vector<vector<string>> plans)
{
	std::sort(plans.begin(), plans.end(), [](const std::vector<string>& _First, const std::vector<string>& _Second)
		{
			return _First[1] < _Second[1];
		});

	std::vector<std::string> answer;
	std::stack<std::tuple<const std::string, int, int>> RemainPlans;

	for (const std::vector<std::string>& _CurPlan : plans)
	{
		if (3 != _CurPlan.size())
		{
			// Error
			return { "계획이 잘못 들어왔습니다." };
		}

		// 스택에 계획이 들어있으면 계산
		if (false == RemainPlans.empty())
		{
			int CurTime = CalcuTime(_CurPlan[1]) - get<1>(RemainPlans.top());

			while (0 < CurTime && false == RemainPlans.empty())
			{
				int& PrevPlanTime = get<2>(RemainPlans.top());
				int SavePrevTime = PrevPlanTime;
				PrevPlanTime -= CurTime;
				CurTime -= SavePrevTime;

				if (PrevPlanTime > 0)
				{
					continue;
				}

				answer.push_back(get<0>(RemainPlans.top()));
				RemainPlans.pop();
			}
		}

		RemainPlans.push(std::make_tuple(_CurPlan[0], CalcuTime(_CurPlan[1]), std::stoi(_CurPlan[2])));
	}

	while (false == RemainPlans.empty())
	{
		answer.push_back(get<0>(RemainPlans.top()));
		RemainPlans.pop();
	}

	return answer;
}