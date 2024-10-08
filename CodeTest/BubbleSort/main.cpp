
#include <vector>
template <typename DataType>
void BubbleSort(std::vector<DataType>& InVector)
{
	const size_t InVectorSize = InVector.size();
	if (1 >= InVectorSize)
	{
		return;
	}

	for (size_t i = 0; i < InVectorSize - 1; i++)
	{
		for (size_t StartIndex = 0; StartIndex < InVectorSize - i - 1; StartIndex++)
		{
			if (InVector[StartIndex] > InVector[StartIndex + 1])
			{
				std::swap(InVector[StartIndex], InVector[StartIndex + 1]);
			}
		}
	}
}

#include <string>
int main()
{
	std::vector<int> Input1 = {7,3,1,2,3,7,0,201,31924,7,41,4,7};
	BubbleSort(Input1);
	std::vector<std::string> Input2 = { "12312", "A", "adas", "qwekd", "askovkq", "asokcao", "asjc", "askocaos", "aockoq4qow" , "dlqopwp" };
	BubbleSort(Input2);
	
	return 0;
}