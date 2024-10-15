#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/43163

using namespace std;

int DiffCountofString(const std::string& First, const std::string& Second)
{
	const size_t First_size = First.size();
	if (First_size != Second.size())
	{
		// Error
		return -1;
	}

	int answer = 0;
	for (size_t i = 0; i < First_size; i++)
	{
		if (First[i] != Second[i])
		{
			++answer;
		}
	}

	return answer;
}

#include <algorithm>
#include <queue>
int solution(string begin, string target, vector<string> words)
{
	// words에 target이 존재하지 않으면 return 0;
	std::vector<std::string>::iterator FindIter = std::find(words.begin(), words.end(), target);
	if (words.end() == FindIter)
	{
		return 0;
	}
	size_t FindIndex = std::distance(words.begin(), FindIter);

	const size_t words_size = words.size();
	// String - ChangeCount Mapping
	std::queue<std::pair<std::string, int>> BFSQueue;
	std::vector<int> ChangeCount(words_size, 0);
	for (size_t i = 0; i < words_size; i++)
	{
		if (1 == DiffCountofString(begin, words[i]))
		{
			BFSQueue.push(std::make_pair(words[i], 1));
			ChangeCount[i] = 1;
		}
	}

	while (false == BFSQueue.empty())
	{
		const std::string CurString = BFSQueue.front().first;
		const int CurCount = BFSQueue.front().second;
		BFSQueue.pop();

		for (size_t i = 0; i < words_size; i++)
		{
			if (0 != ChangeCount[i])
			{
				continue;
			}

			if (1 == DiffCountofString(CurString, words[i]))
			{
				BFSQueue.push(std::make_pair(words[i], CurCount + 1));
				ChangeCount[i] = CurCount + 1;
			}
		}
	}

	return ChangeCount[FindIndex];
}