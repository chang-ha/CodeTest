#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/12954

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
		return "�輭���� �����ϴ�.";
	}

	return "�輭���� " + std::to_string(KimIndex) + "�� �ִ�";
}