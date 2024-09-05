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

	return;
}
#include <stack>
vector<string> solution(vector<vector<string>> plans) 
{
    std::vector<std::string> answer;
	std::stack<std::vector<std::string>> RemainPlans;

	for (const std::vector<std::string>& _CurPlan : plans)
	{
		if (3 != _CurPlan.size())
		{
			// Error
			return {"계획이 잘못 들어왔습니다."};
		}

		if (false == RemainPlans.empty())
		{
		}

		RemainPlans.push(_CurPlan);
	}

    return answer;
}