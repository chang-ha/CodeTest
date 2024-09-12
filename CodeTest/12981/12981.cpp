#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12981

using namespace std;

#include <unordered_set>
vector<int> solution(int n, vector<string> words) 
{
	const std::string& StartWord = words[0];
	if (2 > StartWord.size())
	{
		return { 1,1 };
	}
	char PrevLastWord = StartWord.back();

	std::unordered_set<std::string> WordSet;
	WordSet.insert(StartWord);

	const size_t words_size = static_cast<int>(words.size());
	for (int i = 1; i < words_size; i++)
	{
		const std::string& CurWord = words[i];
		if (2 > CurWord.size() || PrevLastWord != CurWord[0] || WordSet.end() != WordSet.find(CurWord))
		{
			return {i % n + 1, i / n + 1};
		}

		WordSet.insert(CurWord);
		PrevLastWord = CurWord.back();
	}

	return {0, 0};
}