#include <vector>

// 평균적으로 O(N * log N)
// 피벗값을 잘못 설정할 시 최악의 경우 O(N^2)
//	-> 이미 정렬이 되어있는 경우 (1,2,3,4,5,6,7,8,9,10)
//		-> 피벗 1설정 -> 1을 제외하고 작은 수 X (N탐색)
//			-> 1과 자기 자신을 swap -> 1만 정렬 (분할 탐색이 안됨) -> 이를 N번 반복함 (2,3,4,5,6...)
// 대신 삽입 정렬 (Insertion Sort)는 정렬 된 경우 매우 빠르게 수행 가능

template <typename DataType>
void QuickSort(std::vector<DataType>& InVector, const int Start, const int End)
{
	// 원소가 1개인 경우
	if (Start >= End)
	{
		return;
	}

	// 피벗은 첫 번째 원소를 선택
	const int Pivot = Start;
	int BigValueIndex = Start + 1;
	int SmallValueIndex = End;

	while (BigValueIndex <= SmallValueIndex)
	{
		// 범위를 넘지 않는 선에서 피벗보다 큰 값을 만날 떄 까지 이동
		while (BigValueIndex <= End && InVector[Pivot] >= InVector[BigValueIndex])
		{
			++BigValueIndex;
		}
		// 범위를 넘지 않는 선에서 피벗보다 작은 값을 만날 떄 까지 이동
		while (SmallValueIndex > Start && InVector[Pivot] <= InVector[SmallValueIndex])
		{
			--SmallValueIndex;
		}

		// 엇갈린 상태면 피벗값과 교체
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