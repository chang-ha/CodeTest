#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> stk;

	size_t Array_Size = arr.size();
	if (0 == Array_Size)
	{
		return stk;
	}

	stk.push_back(arr[0]);

	for (size_t i = 1; i < Array_Size;)
	{
		if (stk.back() < arr[i])
		{
			stk.push_back(arr[i]);
			++i;
		}
		else
		{
			stk.pop_back();
		}
	}

    return stk;
}