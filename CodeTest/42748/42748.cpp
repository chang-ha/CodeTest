#include <string>
#include <vector>

using namespace std;

// Vector & std::sort
#include <algorithm>
vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	size_t Commands_Size = commands.size();
	vector<int> answer;
	answer.reserve(Commands_Size);

	int Array_Size = static_cast<int>(array.size());
	vector<int> SortVector;
	for (const vector<int>& _CurCommands : commands)
	{
		int StartIndex = _CurCommands[0] - 1;
		int EndIndex = _CurCommands[1] - 1;
		int Priority = _CurCommands[2] - 1;
		if (0 > StartIndex)
		{
			// Error
			return answer;
		}

		if (Array_Size < EndIndex)
		{
			// Error
			return answer;
		}

		if (Priority > EndIndex - StartIndex)
		{
			// Error
			return answer;
		}
		SortVector.clear();
		SortVector.resize(EndIndex - StartIndex + 1);
		std::copy(array.begin() + StartIndex, array.begin() + EndIndex + 1, SortVector.begin());
		std::sort(SortVector.begin(), SortVector.end());

		answer.push_back(SortVector[Priority]);
	}
	return answer;
}

//vector<int> Constructorsolution(vector<int> array, vector<vector<int>> commands)
//{
//	size_t Commands_Size = commands.size();
//	vector<int> answer;
//	answer.reserve(Commands_Size);
//
//	int Array_Size = static_cast<int>(array.size());
//	vector<int> SortVector;
//	for (const vector<int>& _CurCommands : commands)
//	{
//		int StartIndex = _CurCommands[0] - 1;
//		int EndIndex = _CurCommands[1] - 1;
//		int Priority = _CurCommands[2] - 1;
//		if (0 > StartIndex)
//		{
//			// Error
//			return answer;
//		}
//
//		if (Array_Size < EndIndex)
//		{
//			// Error
//			return answer;
//		}
//
//		if (Priority > EndIndex - StartIndex)
//		{
//			// Error
//			return answer;
//		}
//		SortVector.reserve(EndIndex - StartIndex + 1);
//		SortVector = std::vector<int>(array.begin() + StartIndex, array.begin() + EndIndex + 1);
//		std::sort(SortVector.begin(), SortVector.end());
//
//		answer.push_back(SortVector[Priority]);
//	}
//	return answer;
//}

// Queue
//#include <queue>
//vector<int> Queuesolution(vector<int> array, vector<vector<int>> commands)
//{
//	size_t Commands_Size = commands.size();
//	vector<int> answer;
//	answer.reserve(Commands_Size);
//
//	int Array_Size = static_cast<int>(array.size());
//	for (const vector<int>& _CurCommands : commands)
//	{
//		int StartIndex = _CurCommands[0] - 1;
//		int EndIndex = _CurCommands[1] - 1;
//		int Priority = _CurCommands[2];
//		if (0 > StartIndex)
//		{
//			// Error
//			return answer;
//		}
//
//		if (Array_Size < EndIndex)
//		{
//			// Error
//			return answer;
//		}
//
//		if (Priority > EndIndex - StartIndex + 1)
//		{
//			// Error
//			return answer;
//		}
//
//		std::priority_queue<int, vector<int>, std::greater<int>> SortQueue;
//		for (int i = 0; i <= EndIndex - StartIndex; i++)
//		{
//			SortQueue.push(array[StartIndex + i]);
//		}
//
//		while (--Priority)
//		{
//			SortQueue.pop();
//		}
//
//		answer.push_back(SortQueue.top());
//	}
//	return answer;
//}