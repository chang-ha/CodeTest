#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2)
{
    string answer = "";

    size_t Str1_Size = str1.size();
    size_t Str2_Size = str2.size();

    if (Str1_Size != Str2_Size)
    {
        // Error
        return answer;
    }

    answer.resize(Str1_Size + Str2_Size);

    for (size_t i = 0; i < Str1_Size; i++)
    {
        answer[2 * i] = str1[i];
    }

    for (size_t i = 0; i < Str2_Size; i++)
    {
        answer[2 * i + 1] = str2[i];
    }

    return answer;
}