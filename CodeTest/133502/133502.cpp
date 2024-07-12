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

        // (1231의 크기 = 4)보다 작으면 continue 
        if (4 > CurStringSize)
        {
            continue;
        }

        // (ooo1) 현재 string이 1아니면 continue
        if (1 != _CurIngredient)
        {
            continue;
        }

        // 끝에서부터 4글자가 1231이면
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
