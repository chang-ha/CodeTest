#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr)
{
    string answer = "";

    size_t Array_Size = arr.size();
    answer.reserve(Array_Size);

    for (size_t i = 0; i < Array_Size; i++)
    {
        answer += arr[i];
    }

    return answer;
}

int main()
{
    solution({"a", "b", "c"});
}
