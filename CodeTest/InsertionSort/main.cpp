#include <vector>

// 평균적으로 O(N^2) 의 시간 복잡도를 가지는데
// 삽입 정렬은 원소의 갯수가 작은 경우 or 거의 정렬된 상태에서는 굉장히 빠름

template <typename DataType>
void InsertionSort(std::vector<DataType>& InVector)
{
	const size_t InVectorSize = InVector.size();
	if (1 >= InVectorSize)
	{
		return;
	}

	for (int SortIndex = 1; SortIndex < InVectorSize; SortIndex++)
	{
		DataType SortedValue = InVector[SortIndex];
		// can't use size_t -> size_t 0 - size_t 1 = INT_MAX
		int SortedIndex = SortIndex - 1;
		while (0 <= SortedIndex && SortedValue < InVector[SortedIndex])
		{
			std::swap(InVector[SortedIndex], InVector[SortedIndex + 1]);
			--SortedIndex;
		}
	}
}

#include <string>
int main()
{
	std::vector<int> Input1 = { 1,3,5,2,1,48,3,1,4,5,45,123,63,123,67,33,1,767,40 };
	InsertionSort(Input1);
	std::vector<std::string> Input2 = { "asdasd" "AISJDK", "asdjiqA", "asjviasd", "fccv", "a", "A", "qwoikqow" };
	InsertionSort(Input2);

	return 0;
}