#include <string>
#include <vector>

using namespace std;

#include <algorithm>
vector<string> solution(string my_string) 
{
    vector<string> answer;

    size_t String_Size = my_string.size();
    answer.reserve(String_Size);

    for (size_t i = 0; i < String_Size; i++)
    {
        answer.push_back(my_string.substr(i));
    }

    std::sort(answer.begin(), answer.end());
    return answer;
}