#include <string>
#include <vector>

using namespace std;

#include <set>
int solution(string my_string, string is_suffix)
{
    std::set<string> Subset;

    size_t String_Size = my_string.size();
    for (size_t i = 0; i < String_Size; i++)
    {
        Subset.insert(my_string.substr(i));
    }

    if (Subset.end() == Subset.find(is_suffix))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}