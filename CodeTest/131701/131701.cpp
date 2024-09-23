#include <string>
#include <vector>

// 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/131701

using namespace std;

// 연속된 값들을 더해야함 -> ex) 불가능한 조합 { 7 1 4 }
// prefix 활용

#include <set>
// Dynamic Programming(DP) 활용
int solution(vector<int> elements)
{
	const size_t elements_size = elements.size();
	const size_t elements_doublesize = elements_size * 2;

	std::vector<int> Prefix_Sum(elements_doublesize, 0);
	Prefix_Sum[0] = elements[0];

	for (size_t i = 1; i < elements_doublesize; i++)
	{
		// 7 9 1 1 4
		// -> 7 9 1 1 4 7 9 1 1 4
		// i ~ j
		// 범위를 2배로 늘려서 prefix 계산
		//   -> 원형 형태로 계산하기 위함
		Prefix_Sum[i] = Prefix_Sum[i - 1] + elements[i % elements_size];
	}

	std::set<int> element_count;
	for (size_t i = 0; i < elements_size; i++)
	{
		// i보다 1개 이상의 원소가 포함된 prefix_sum
		// prefix_sum[i + j] -> 0 ~ i + j까지 prefix_sum
		// prefix_sum[i] -> 0 ~ i까지 prefix_sum
		// prefix_sum[i + j] - prefix_sum[i] -> (i + 1) ~ j 의 prefix_sum
		for (size_t j = 1; j <= elements_size; j++)
		{
			element_count.insert(Prefix_Sum[i + j] - Prefix_Sum[i]);
		}
	}

	return static_cast<int>(element_count.size());
}

// "다른 사람의 코드"
// DP로 이전 sum 값을 저장해놓는데 runtime 더 효율적임
int Othersolution(vector<int> elements)
{
	std::set<int> S;

	int n = static_cast<int>(elements.size());

	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = i; j < i + n; ++j) {
			sum += elements[j % n];
			S.insert(sum);
		}
	}

	return static_cast<int>(S.size());
}

#include <set>
#include <cmath>
int bitsolution(vector<int> elements)
{
	const size_t elements_size = elements.size(); // n << n개의 비트 사용
	std::set<int> element_count;
	const size_t LoopCount = static_cast<size_t>(std::pow(2, elements_size));
	// bit or graycode 사용시
	// 2 ^ n 이므로 포기
	return static_cast<int>(element_count.size());
}