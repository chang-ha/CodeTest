#include <string>
#include <vector>

using namespace std;

// 3 <= number <= 13 -> vector(Input)의 길이는 작음
// Input이 작으니까 브루트 포스 알고리즘
#include <algorithm>
int solution(vector<int> number) 
{
    int answer = 0;
    std::sort(number.begin(), number.end());

    int Number_Size = static_cast<int>(number.size());
    for (int i = 0; i < Number_Size - 2; i++)
    {
        for (int j = i + 1; j < Number_Size - 1; j++)
        {
            for (int k = j + 1; k < Number_Size; k++)
            {
                int Sum = number[i] + number[j] + number[k];
                if (0 == Sum)
                {
                    ++answer;
                }
                else if (0 < Sum)
                {
                    break;
                }
            }
        }
    }

    return answer;
}