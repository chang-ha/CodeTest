#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/42747

using namespace std;

#include <algorithm>

// 3 0 6 1 5
// sort : 6 5 3 1 0 
// i = 0 >= a[0] = 6 ? X	<< 6(a[i])���� ū �� 0(i)�� 
// i = 1 >= a[1] = 5 ? X	<< 5(a[i])���� ū �� 1(i)�� (&& ��� ���� 6���� ũ�ų� ����)
// i = 2 >= a[2] = 3 ? X	<< 3(a[i])���� ū �� 2(i)�� (&& ��� ���� 5���� ũ�ų� ����)
// i = 3 >= a[3] = 1 ? O	<< 1(a[i])���� ū �� 3(i)�� (&& ��� ���� 3���� ũ�ų� ����)
//								-> ������ ���� ���� �ɸ��� ���� �ִ밪
// return 3

// 0
// 0 >= 0 << 0���� ū �� 0��
// return 0

// 4 3
// 1 > 4
// 2 > 3
// ��� ���� size(2)���� ŭ
// return 2;

// 999 998 997 996 995
// i = 0 >= a[0] = 999 ? X
// i = 1 >= a[1] = 998 ? X
// i = 2 >= a[2] = 997 ? X
// i = 3 >= a[3] = 996 ? X
// i = 4 >= a[4] = 995 ? X
// ��� ���� size(5)���� ŭ
// return 5

// 9 7 6 2 1

int solution(vector<int> citations)
{
	std::sort(citations.begin(), citations.end(), std::greater<int>());

	const int citations_size = static_cast<int>(citations.size());
	for (int i = 0; i < citations_size; i++)
	{
		if (i >= citations[i])
		{
			return i;
		}
	}

	return citations_size;
}

// 3 0 6 1 5
// l_sort : 0 1 3 5 6
// 0 -> 5
// 1 -> 4
// 3 -> 3
// 5 -> 2
// 6 -> 1

// 3 4 
// 3 -> 2
// 4 -> 1

// 1 11 111 1111
// 1 -> 4
// 11 -> 3
// 111 -> 2
// 1111 -> 1

// 3 5 11 6 1 5 3 3 1 41
// 1 1 3 3 3 5 5 6 11 41
int solution(vector<int> citations)
{
	std::sort(citations.begin(), citations.end());

	const size_t citations_size = citations.size();
	if (0 == citations_size)
	{
		return 0;
	}

	if (citations[0] >= citations_size)
	{
		return static_cast<int>(citations_size);
	}

	int answer = 0;
	for (size_t i = 0; i < citations_size;)
	{
		if (answer > citations[i])
		{
			++i;
			continue;
		}
		else if (citations_size - i >= answer)
		{
			++answer;
		}
		else
		{
			break;
		}
	}

	return answer - 1;
}
