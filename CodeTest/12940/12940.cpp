#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/12940

using namespace std;

vector<int> solution(int n, int m)
{
	// �ִ����� <- ��Ŭ���� ȣ����
	vector<int> answer;
	answer.reserve(2);

	int Dividend = n >= m ? n : m; // ū ��
	int Divisor = n < m ? n : m; // ���� ��
	int Remain = Dividend % Divisor;
	while (0 != Remain)
	{
		Dividend = Divisor;
		Divisor = Remain;
		Remain = Dividend % Divisor;
	}

	// �ִ�����
	answer.push_back(Divisor);
	// �ּҰ���� = �� ���� �� / �ִ�����
	answer.push_back(n * m / Divisor);

	return answer;
}