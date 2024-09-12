#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/131701

using namespace std;

// prefix 활용으로 푸는 중 (답 아직 아님 << 구할수 있는거 맞음??)
#include <set>
#include <numeric>
int solution(vector<int> elements)
{
	const size_t elements_size = elements.size();
	const size_t elements_doublesize = elements_size * 2;

	std::vector<int> Prefix_Sum(elements_doublesize, 0);
	Prefix_Sum[0] = elements[0];

	for (size_t i = 1; i < elements_doublesize; i++)
	{
		Prefix_Sum[i] = Prefix_Sum[i - 1] + elements[i % elements_size];
	}

	std::set<int> element_count;
	for (size_t i = 1; i <= elements_size; i++)
	{
		for (size_t j = 0; j < elements_size; j++)
		{
			int a = Prefix_Sum[i + j]; // 0 ~ i + j 까지
			int b = Prefix_Sum[j]; // 0 ~ j 까지
			int sum = a - b; // i ~ j 까지
			element_count.insert(sum);
			// std::cout << "1. 0 ~ " << i + j << " : " << a << std::endl;
			// std::cout << "2. 0 ~ " << j << " : " << b << std::endl;
			// std::cout << "3. " << j << " ~ " << i << " : " << sum << std::endl;
			// std::cout << "===============" << std::endl;
		}
	}

	return static_cast<int>(element_count.size());
}

#include <set>
int bitsolution(vector<int> elements)
{
	const size_t elements_size = elements.size(); // n << n개의 비트 사용
	std::set<int> element_count;
	const size_t LoopCount = static_cast<size_t>(std::pow(2, elements_size));
	// bit or graycode 사용시
	// 2 ^ n 이므로 포기
	return static_cast<int>(element_count.size());
}