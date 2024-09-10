#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/12911

using namespace std;

// n >= 1'000'000 -> 11110100001001000000
#include <bitset>
int solution(int n)
{
	const size_t OneCount_n = std::bitset<20>(n).count();

	int answer = n;
	for (size_t OneCount_answer = 0; OneCount_n != OneCount_answer; ++answer, OneCount_answer = std::bitset<20>(answer).count())
	{
	}

	return answer;
}
