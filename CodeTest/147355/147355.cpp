#include <string>
#include <vector>

using namespace std;

int solution(string t, string p)
{
    int answer = 0;

    size_t P_Size = p.size();

    size_t T_Size = t.size();
    for (size_t i = 0; i <= T_Size - P_Size; i++)
    {
        std::string T_Substr = t.substr(i, P_Size);

        if (p >= T_Substr)
        {
            answer += 1;
        }
    }

    return answer;
}