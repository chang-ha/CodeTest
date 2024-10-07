#include <algorithm>

//		   i-1   i
// 7 1 3	2	 5 4 1
//				 1 4 5

template <class IterClass>
bool MY_next_permutation(IterClass Begin, IterClass End)
{
	IterClass tBegin = Begin;
	const IterClass tEnd = End;
	IterClass tNext = tEnd;
	
	// ����ְų�, ũ�Ⱑ 1���� IterClass
	if (tBegin == tEnd || tBegin == --tNext)
	{
		return false;
	}

	for (;;)
	{
		// tNext = i - 1
		// tNext2 = i
		IterClass tNext2 = tNext;
        // a[i - 1] < a[i]�� �����ϴ� ���� ū i���� ã�� (���������� �ƴ� �κ��� Ž��)
        if (*--tNext < *tNext2)
        {
			// i < j�� �����ϸ鼭 
			// a[i-1] < a[j] �ּҰ� ã��
			IterClass tMid = tEnd;
			// �տ��� �̹� ���������� �κб��� Ž���߱� ������
			// *tNext < *tMid �� ���� a[i-1] < a[j]�� �����ϴ� �ּҰ�
			do
			{
				--tMid;
			} while (*tNext >= *tMid); 

			// �� ���Ҹ� ����
			std::swap(*tNext, *tMid);
			// a[i]���� ������ ���� ������
			std::reverse(tNext2, tEnd);
			return true;
        }

		// ������ ������������ ���ĵǾ� �ִ� ��
		// �ٽ� ������ ���� ������ (������������ ����)
		if (tBegin == tNext)
		{
			std::reverse(tBegin, tEnd);
			return false;
		}
	}
}

template <class IterClass>
bool MY_prev_permutation(IterClass Begin, IterClass End)
{
	IterClass tBegin = Begin;
	const IterClass tEnd = End;
	IterClass tNext = tEnd;

	if (tBegin == tEnd || tBegin == --tNext)
	{
		return false;
	}

	for (;;)
	{
		IterClass tNext2 = tNext;
		if (*--tNext > *tNext2)
		{
			IterClass tMid = tEnd;
			do
			{
				--tMid;
			} while (*tNext <= *tMid);

			std::swap(*tNext, *tMid);
			std::reverse(tNext2, tEnd);
			return true;
		}

		if (tBegin == tNext)
		{
			std::reverse(tBegin, tEnd);
			return false;
		}
	}
}

#include <vector>
#include <iostream>
int main()
{
	std::vector<int> Input1 = { 1,2,3,4,4 };
	std::vector<int> Input2 = { 1,2,3,4,4 };
	do
	{
		std::vector<int>::const_iterator StartIter = Input1.begin();
		std::vector<int>::const_iterator EndIter = Input1.end();
		for (;StartIter != EndIter; ++StartIter)
		{
			std::cout << *StartIter;
		}
		std::cout << std::endl;

		std::vector<int>::const_iterator StartIter2 = Input2.begin();
		std::vector<int>::const_iterator EndIter2 = Input2.end();
		for (; StartIter2 != EndIter2; ++StartIter2)
		{
			std::cout << *StartIter2;
		}
		std::cout << std::endl;
	} while (MY_next_permutation(Input1.begin(), Input1.end()) && std::next_permutation(Input2.begin(), Input2.end()));

	Input1 = { 4,4,3,2,1};
	Input2 = { 4,4,3,2,1};

	std::cout << "--------------------" << std::endl;

	do
	{
		std::vector<int>::const_iterator StartIter = Input1.begin();
		std::vector<int>::const_iterator EndIter = Input1.end();
		for (; StartIter != EndIter; ++StartIter)
		{
			std::cout << *StartIter;
		}
		std::cout << std::endl;

		std::vector<int>::const_iterator StartIter2 = Input2.begin();
		std::vector<int>::const_iterator EndIter2 = Input2.end();
		for (; StartIter2 != EndIter2; ++StartIter2)
		{
			std::cout << *StartIter2;
		}
		std::cout << std::endl;
	} while (MY_prev_permutation(Input1.begin(), Input1.end()) && prev_permutation(Input2.begin(), Input2.end()));
}