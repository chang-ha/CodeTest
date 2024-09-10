#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/150368

using namespace std;

// 이모티콘 최대 e
// 경우의수 4^e
// 브루트 포스 사용

#include <array>
vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
	vector<int> answer(2, 0);

	static std::array<float, 4> DiscountRatio = { 0.9f, 0.8f, 0.7f, 0.6f };

	std::vector<float> DiscountEmoticons(emoticons.size(), 0.f);


	return answer;
}