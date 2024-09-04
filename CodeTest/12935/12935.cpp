#include <string>
#include <vector>

using namespace std;

#include <limits.h>
vector<int> solution(vector<int> arr) 
{
    int arr_size = static_cast<int>(arr.size());

    if (1 == arr_size)
    {
        return std::vector<int>(1, -1);
    }

    vector<int> answer;
    answer.reserve(arr_size - 1);

    int Min_Value = INT_MAX;
    int Index = 0;

    for (int i = 0; i < arr_size; i++)
    {
        if (Min_Value > arr[i])
        {
            Min_Value = arr[i];
            Index = i;
        }
    }

    for (int i = 0; i < arr_size; i++)
    {
        if (i == Index)
        {
            continue;   
        }

        answer.push_back(arr[i]);
    }

    return answer;
}