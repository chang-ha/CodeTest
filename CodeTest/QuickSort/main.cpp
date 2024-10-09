#include <vector>

// ��������� O(N * log N)
// �ǹ����� �߸� ������ �� �־��� ��� O(N^2)
//	-> �̹� ������ �Ǿ��ִ� ��� (1,2,3,4,5,6,7,8,9,10)
//		-> �ǹ� 1���� -> 1�� �����ϰ� ���� �� X (NŽ��)
//			-> 1�� �ڱ� �ڽ��� swap -> 1�� ���� (���� Ž���� �ȵ�) -> �̸� N�� �ݺ��� (2,3,4,5,6...)
// ��� ���� ���� (Insertion Sort)�� ���� �� ��� �ſ� ������ ���� ����

template <typename DataType>
void QuickSort(std::vector<DataType>& InVector, const int Start, const int End)
{
	// ���Ұ� 1���� ���
	if (Start >= End)
	{
		return;
	}

	// �ǹ��� ù ��° ���Ҹ� ����
	const int Pivot = Start;
	int BigValueIndex = Start + 1;
	int SmallValueIndex = End;

	while (BigValueIndex <= SmallValueIndex)
	{
		// ������ ���� �ʴ� ������ �ǹ����� ū ���� ���� �� ���� �̵�
		while (BigValueIndex <= End && InVector[Pivot] >= InVector[BigValueIndex])
		{
			++BigValueIndex;
		}
		// ������ ���� �ʴ� ������ �ǹ����� ���� ���� ���� �� ���� �̵�
		while (SmallValueIndex > Start && InVector[Pivot] <= InVector[SmallValueIndex])
		{
			--SmallValueIndex;
		}

		// ������ ���¸� �ǹ����� ��ü
		if (BigValueIndex > SmallValueIndex)
		{
			std::swap(InVector[Pivot], InVector[SmallValueIndex]);
		}
		else
		{
			std::swap(InVector[BigValueIndex], InVector[SmallValueIndex]);
		}
	}

	QuickSort(InVector, Start, SmallValueIndex - 1);
	QuickSort(InVector, SmallValueIndex + 1, End);
}

int main()
{
	std::vector<int> Input1 = { 9,3,2,5,3,1,7,6,4,2,1 };
	QuickSort(Input1, 0, static_cast<int>(Input1.size()) - 1);
	return 0;
}