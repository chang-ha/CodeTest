#include <iostream>
#include <TimeCheck\TimeCheck.h>

#include <string>
#include <vector>

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
vector<string> solution(vector<vector<string>> plans)
{
	std::vector<std::string> answer;
	std::stack<std::tuple<const std::string, int, int>> RemainPlans;

	for (const std::vector<std::string>& _CurPlan : plans)
	{
		if (3 != _CurPlan.size())
		{
			// Error
			return { "계획이 잘못 들어왔습니다." };
		}

		if (false == RemainPlans.empty())
		{

		}

		RemainPlans.push(std::make_tuple(_CurPlan[0], CalcuTime(_CurPlan[1]), std::stoi(_CurPlan[2])));
	}

	return answer;
}

int main()
{
	solution({ {"korean", "11:40", "30" }, {"english", "12:10", "20"}, { "math", "12:30", "40" }});
	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT ETime = CheckFunctionTime([&]()
		{
		});

	std::cout << "ATime is " << ATime.count() << " microseconds" << std::endl;
	std::cout << "BTime is " << BTime.count() << " microseconds" << std::endl;
	std::cout << "CTime is " << CTime.count() << " microseconds" << std::endl;
	std::cout << "DTime is " << DTime.count() << " microseconds" << std::endl;
	std::cout << "ETime is " << ETime.count() << " microseconds" << std::endl;
	int x = 0;
}