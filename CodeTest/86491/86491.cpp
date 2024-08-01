#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    size_t Vector_Size = sizes.size();

    if (0 == Vector_Size)
    {
        return 0;
    }

    // X, Y중에서
    // X를 긴 길이로 통일 << 규칙 지정
    int X_Length = 0;
    int Y_Length = 0;

    for (size_t i = 0; i < Vector_Size; i++)
    {
        if (2 != sizes[i].size())
        {
            return -1;
        }

        // Y값이 X값보다 크면 swap;
        if (sizes[i][1] > sizes[i][0])
        {
            std::swap(sizes[i][0], sizes[i][1]);
        }

        X_Length = X_Length > sizes[i][0] ? X_Length : sizes[i][0];
        Y_Length = Y_Length > sizes[i][1] ? Y_Length : sizes[i][1];
    }

    return X_Length * Y_Length;
}

int Prevsolution(vector<vector<int>> sizes)
{

    size_t Vector_Size = sizes.size();

    if (0 == Vector_Size)
    {
        return 0;
    }

    int X_Length = sizes[0][0];
    int Y_Length = sizes[0][1];

    int answer = X_Length * Y_Length;

    if (1 == Vector_Size)
    {
        return answer;
    }

    for (size_t i = 1; i < Vector_Size; i++)
    {
        if (2 != sizes[i].size())
        {
            return -1;
        }

        int Cur_X = X_Length > sizes[i][0] ? X_Length : sizes[i][0];
        int Cur_Y = Y_Length > sizes[i][1] ? Y_Length : sizes[i][1];

        int Reverse_X = X_Length > sizes[i][1] ? X_Length : sizes[i][1];
        int Reverse_Y = Y_Length > sizes[i][0] ? Y_Length : sizes[i][0];

        int Size = Cur_X * Cur_Y;
        int ReverseSize = Reverse_X * Reverse_Y;

        if (Size > ReverseSize)
        {
            answer = ReverseSize;
            X_Length = Reverse_X;
            Y_Length = Reverse_Y;
        }
        else
        {
            answer = Size;
            X_Length = Cur_X;
            Y_Length = Cur_Y;
        }
    }

    return answer;
}