
#include <vector>

template <typename DataType>
void SelectionSort(std::vector<DataType>& InVector)
{
	const size_t InVectorSize = InVector.size();
	if (1 >= InVectorSize)
	{
		return;
	}

	for (size_t SortIndex = 0; SortIndex < InVectorSize; SortIndex++)
	{
		size_t SortedIndex = SortIndex;
		for (size_t i = SortIndex + 1; i < InVectorSize; i++)
		{
			if (InVector[SortedIndex] > InVector[i])
			{
				SortedIndex = i;
			}
		}

		if (SortedIndex != SortIndex)
		{
			std::swap(InVector[SortIndex], InVector[SortedIndex]);
		}
	}
}

#include <string>
int main()
{
	std::vector<int> Input1 = { 9,1,4,2,3,5,8,2,1,5,8,0,5 };
	SelectionSort(Input1);
	std::vector<std::string> Input2 = { "as", "B", "CCC", "asdkas", "qwoeq", "daDF" };
	SelectionSort(Input2);

	return 0;
}