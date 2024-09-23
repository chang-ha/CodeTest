#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/131701

using namespace std;

// ���ӵ� ������ ���ؾ��� -> ex) �Ұ����� ���� { 7 1 4 }
// prefix Ȱ��

#include <set>
// Dynamic Programming(DP) Ȱ��
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
		// ������ 2��� �÷��� prefix ���
		//   -> ���� ���·� ����ϱ� ����
		Prefix_Sum[i] = Prefix_Sum[i - 1] + elements[i % elements_size];
	}

	std::set<int> element_count;
	for (size_t i = 0; i < elements_size; i++)
	{
		// i���� 1�� �̻��� ���Ұ� ���Ե� prefix_sum
		// prefix_sum[i + j] -> 0 ~ i + j���� prefix_sum
		// prefix_sum[i] -> 0 ~ i���� prefix_sum
		// prefix_sum[i + j] - prefix_sum[i] -> (i + 1) ~ j �� prefix_sum
		for (size_t j = 1; j <= elements_size; j++)
		{
			element_count.insert(Prefix_Sum[i + j] - Prefix_Sum[i]);
		}
	}

	return static_cast<int>(element_count.size());
}

// "�ٸ� ����� �ڵ�"
// DP�� ���� sum ���� �����س��µ� runtime �� ȿ������
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
	const size_t elements_size = elements.size(); // n << n���� ��Ʈ ���
	std::set<int> element_count;
	const size_t LoopCount = static_cast<size_t>(std::pow(2, elements_size));
	// bit or graycode ����
	// 2 ^ n �̹Ƿ� ����
	return static_cast<int>(element_count.size());
}