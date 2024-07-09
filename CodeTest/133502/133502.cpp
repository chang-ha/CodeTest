#include <string>
#include <vector>

using namespace std;

// String조작은 느림
int solution(vector<int> ingredient)
{
    int answer = 0;
    std::string StringIngredient;

    for (const int _CurIngredient : ingredient)
    {
        StringIngredient += std::to_string(_CurIngredient);
        size_t CurStringSize = StringIngredient.size();

        if (4 > CurStringSize)
        {
            continue;
        }

        if (1 != _CurIngredient)
        {
            continue;
        }

        if ("1231" == StringIngredient.substr(CurStringSize - 4))
        {
            StringIngredient.erase(CurStringSize - 4);
            ++answer;
        }
    }

    return answer;
}

int Othersolution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = { -1 };
    for (int x : ingredient) {
        if (v.back() == 1 && x == 2) v.back() = 12;
        else if (v.back() == 12 && x == 3) v.back() = 123;
        else if (v.back() == 123 && x == 1) answer++, v.pop_back();
        else v.push_back(x);
    }

    return answer;
}
