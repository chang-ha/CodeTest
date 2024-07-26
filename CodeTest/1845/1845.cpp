#include <vector>
using namespace std;

#include <unordered_set>
int solution(vector<int> nums)
{
    std::unordered_set<int> PokemonSet(nums.begin(), nums.end());

    int NumSize = static_cast<int>(nums.size());
    NumSize /= 2;
    int SetSize = static_cast<int>(PokemonSet.size());
    return NumSize < SetSize ? NumSize : SetSize;
}