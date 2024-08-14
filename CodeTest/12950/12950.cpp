#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    size_t Arr1_Col_Size = arr1.size();

    if (arr2.size() != Arr1_Col_Size)
    {
        // Error
        return {};
    }

    vector<vector<int>> answer(Arr1_Col_Size);

    for (size_t i = 0; i < Arr1_Col_Size; i++)
    {
        size_t Arr1_Row_Size = arr1[i].size();

        if (arr2[i].size() != Arr1_Row_Size)
        {
            return {};
        }

        answer[i].resize(Arr1_Row_Size);

        for (size_t j = 0; j < Arr1_Row_Size; j++)
        {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    return answer;
}