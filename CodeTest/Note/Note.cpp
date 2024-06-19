using namespace std;

#include <set>
#include <vector>
#include <algorithm>

int maxMin(int k, vector<int> arr)
{
	int Result = INT_MAX;

	size_t Arr_Size = arr.size();
	if (Arr_Size < k || 1 >= k)
	{
		// Error
		return Result;
	}

	std::sort(arr.begin(), arr.end());

	if (Arr_Size == k)
	{
		Result = arr[Arr_Size - 1] - arr[0];
		return Result;
	}

	size_t LoopCount = Arr_Size - static_cast<size_t>(k) + 1;
	for (size_t i = 0; i < LoopCount; i++)
	{
		Result = std::min(Result, arr[i + k - 1] - arr[i]);
	}
	return Result;
}

int main()
{
	maxMin(3, { 10,100,300,200,1000,20,30 });
}
