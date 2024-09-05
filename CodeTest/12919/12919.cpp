#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/12919

using namespace std;

string solution(vector<string> seoul) 
{
	size_t KimIndex = SIZE_MAX;

	const size_t seoul_size = seoul.size();
	for (size_t i = 0; i < seoul_size; i++)
	{
		if ("Kim" == seoul[i])
		{
			KimIndex = i;
			break;
		}
	}

	if (SIZE_MAX == KimIndex)
	{
		// Error
		return "김서방이 없습니다.";
	}

	std::string answer("김서방은 %d에 있다", KimIndex);

	return answer;
}