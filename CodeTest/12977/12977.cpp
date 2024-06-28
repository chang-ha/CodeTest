#include <vector>
#include <iostream>
using namespace std;

// 에라토스테네스의 체 알고리즘

int FindMaxValue(const std::vector<int>& _FindVector)
{
	int MaxValue = INT_MIN;
	for (const int _CurValue : _FindVector)
	{
		if (_CurValue > MaxValue)
		{
			MaxValue = _CurValue;
		}
	}

	return MaxValue;
}

int solution(vector<int> nums) 
{
    int answer = -1;

	int MaxValue = FindMaxValue(nums);

	std::vector<bool> Eratosthenes(MaxValue, true);

	int Eratosthenes_Size = static_cast<int>(Eratosthenes.size());
	for (int i = 2; i < Eratosthenes_Size; i++)
	{
		for (int j = 2; j < Eratosthenes_Size; j++)
		{
			Eratosthenes[i * j] = false;
		}
	}

	size_t Nums_Size = nums.size();
	for (size_t FirstIndex = 0; FirstIndex < Nums_Size - 2; FirstIndex++)
	{
		for (size_t SecondIndex = FirstIndex + 1; SecondIndex < Nums_Size - 1; SecondIndex++)
		{
			for (size_t ThirdIndex = SecondIndex + 1; ThirdIndex < Nums_Size; ThirdIndex++)
			{
				int Value = nums[FirstIndex] + nums[SecondIndex] + nums[ThirdIndex];
				if (true == Eratosthenes[Value])
				{
					answer += 1;
				}
			}
		}
	}

    return answer;
}