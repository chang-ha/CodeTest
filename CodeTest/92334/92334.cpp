#include <string>
#include <vector>

using namespace std;

#include <map>
#include <set>
vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
	const int Id_Size = static_cast<int>(id_list.size());
	vector<int> answer(Id_Size, 0);

	// 한명이 한명만 신고 할 수 있게
	// 중복 체크를 위해 set 사용
	// 피신고자와 신고자 매핑
	std::map<std::string, std::set<std::string>> ReportMap;
	// 이름과 순서 매핑
	std::map<std::string, int> IdMap;
	for (int i = 0; i < Id_Size; i++)
	{
		IdMap[id_list[i]] = i;
	}


	for (const std::string& _CurReport : report)
	{
		size_t Index = _CurReport.find_first_of(' ');
		// 신고자
		std::string Reporter = _CurReport.substr(0, Index);
		// 피신고자
		std::string ReportedUser = _CurReport.substr(Index + 1);
		ReportMap[ReportedUser].insert(Reporter);
	}

	for (const std::pair<std::string, std::set<std::string>>& _CurPair : ReportMap)
	{
		// k 미만 신고는 무시
		if (k > _CurPair.second.size())
		{
			continue;
		}

		// 피신고자가 정지시 
		for (const std::string& _CurReporter : _CurPair.second)
		{
			answer[IdMap[_CurReporter]] += 1;
		}
	}

	return answer;
}

#include <iostream>
#include <sstream>
vector<int> SStreamsolution(vector<string> id_list, vector<string> report, int k)
{
	const int Id_Size = static_cast<int>(id_list.size());
	vector<int> answer(Id_Size, 0);

	std::map<std::string, std::set<std::string>> ReportMap;
	std::map<std::string, int> IdMap;

	for (int i = 0; i < Id_Size; i++)
	{
		IdMap[id_list[i]] = i;
	}

	for (const std::string& _CurReport : report)
	{
		std::stringstream Input(_CurReport);
		std::string Reporter = "";
		std::string ReportedUser = "";
		Input >> Reporter;
		Input >> ReportedUser;
		ReportMap[ReportedUser].insert(Reporter);
	}

	for (const std::pair<std::string, std::set<std::string>>& _CurPair : ReportMap)
	{
		if (k > _CurPair.second.size())
		{
			continue;
		}

		for (const std::string& _CurReporter : _CurPair.second)
		{
			answer[IdMap[_CurReporter]] += 1;
		}
	}

	return answer;
}

#include <unordered_map>
vector<int> Usolution(vector<string> id_list, vector<string> report, int k)
{
	const int Id_Size = static_cast<int>(id_list.size());
	vector<int> answer(Id_Size, 0);

	std::unordered_map<std::string, std::set<std::string>> ReportMap;
	std::unordered_map<std::string, int> IdMap;

	for (int i = 0; i < Id_Size; i++)
	{
		IdMap[id_list[i]] = i;
	}

	for (const std::string& _CurReport : report)
	{
		size_t Index = _CurReport.find_first_of(' ');
		std::string Reporter = _CurReport.substr(0, Index);
		std::string ReportedUser = _CurReport.substr(Index + 1);
		ReportMap[ReportedUser].insert(Reporter);
	}

	for (const std::pair<std::string, std::set<std::string>>& _CurPair : ReportMap)
	{
		if (k > _CurPair.second.size())
		{
			continue;
		}

		for (const std::string& _CurReporter : _CurPair.second)
		{
			answer[IdMap[_CurReporter]] += 1;
		}
	}

	return answer;
}
