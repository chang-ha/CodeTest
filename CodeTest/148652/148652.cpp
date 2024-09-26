#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/148652

using namespace std;

#include <cmath>
#include <array>
int CalcuCantor(const int n, long long valueRange)
{
	// 5���� ��ȯ
	// 1 1 0 1 1
	// �߰��� 0 section�� �����ϹǷ� 1�� ������ 0->1->2->2->3 �� 
	static std::array<int, 5> quinary = { 0,1,2,2,3 };

	int answer = 0;
	int digit = 0;
	while (0 != valueRange)
	{
		if (2 == valueRange % 5)
		{
			// 5���� ��ȯ �� 2�� ������ 0 section�� �ִٴ� �Ҹ� -> ������ ������ ���� 0���� ��������
			// ex) n == 2�� 0 section�� 10 ~ 15 ���� ��
			//	-> 5���� ��ȯ �� 20 ~ 30 �̹Ƿ� 2���� ������ ������ ������ 1�� ���� 0���� �ʱ�ȭ
			// ex) n == 3�� 0 section�� 50 ~ 75 ���� ��
			//	-> 5���� ��ȯ �� 200 ~ 300  
			answer = 0;
		}
		answer += quinary[valueRange % 5] * static_cast<int>(std::pow(4, digit));
		++digit;
		valueRange /= 5;
	}

	return answer;
}

#include <stdexcept>
int solution(int n, long long l, long long r)
{
	if (1 > n)
	{
		// Error
		throw std::invalid_argument("'n' is wrong argument");
	}

	if (1 > l)
	{
		// Error
		throw std::invalid_argument("'l' is wrong argument");
	}

	// 5^20's digit = 14, double maximum digit = 15
	if (static_cast<long long>(std::pow(5, n)) < r)
	{
		// Error
		throw std::invalid_argument("'r' is wrong argument");
	}

	if (l > r)
	{
		// Error
		throw std::invalid_argument("'l' or 'r' is wrong argument");
	}

	return CalcuCantor(n, r) - CalcuCantor(n, l - 1);
}