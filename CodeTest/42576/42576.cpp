#include <string>
#include <vector>

using namespace std;

#include <algorithm>
string Othersolution(vector<string> participant, vector<string> completion) {
	string answer = "";
	std::sort(participant.begin(), participant.end());
	std::sort(completion.begin(), completion.end());
	int Completion_Size = static_cast<int>(completion.size());
	for (int i = 0; i < Completion_Size; i++)
	{
		if (participant[i] != completion[i])
		{
			return participant[i];
		}
	}
	return participant[participant.size() - 1];
}

#include <unordered_set>
string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";

	// 참가자를 u_map에 담기
	std::unordered_multiset<std::string> ParticipantSet;
	for (const std::string& _CurParticipant : participant)
	{
		ParticipantSet.insert(_CurParticipant);
	}

	// 현재 완주자
	for (const std::string& _CurCompletion : completion)
	{
		std::unordered_multiset<std::string>::const_iterator FindIter = ParticipantSet.find(_CurCompletion);

		// 찾아서 없으면 return
		if (ParticipantSet.end() == FindIter)
		{
			return _CurCompletion;
		}

		// 있으면 참가자 명단에서 제외
		ParticipantSet.erase(FindIter);
	}

	if (false == ParticipantSet.empty())
	{
		answer = *ParticipantSet.begin();
	}
	else
	{
		// Error
		// 모든 참가자가 완주함
	}

	return answer;
}

#include <string_view>
// string string_viewsolution(vector<string> participant, vector<string> completion)
// {
// 	string answer = "";
// 	std::unordered_multiset<std::string> ParticipantSet;
// 	for (std::string_view _CurParticipant : participant)
// 	{
// 		ParticipantSet.insert(_CurParticipant.data());
// 	}
// 
// 	for (std::string_view _CurCompletion : completion)
// 	{
// 		std::unordered_multiset<std::string>::iterator FindIter = ParticipantSet.find(_CurCompletion.data());
// 
// 		if (ParticipantSet.end() == FindIter)
// 		{
// 			answer = _CurCompletion;
// 			break;
// 		}
// 
// 		ParticipantSet.erase(FindIter);
// 	}
// 
// 	if (false == ParticipantSet.empty())
// 	{
// 		answer = *ParticipantSet.begin();
// 	}
// 
// 	return answer;
// }