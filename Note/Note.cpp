#include <bits/stdc++.h>

using namespace std;

long countTriplets(vector<long> arr, long r)
{
    std::unordered_map<long, long> InputMap;

    int arrSize = static_cast<int>(arr.size());
    for (int i = 0; i < arrSize; i++)
    {
        InputMap[arr[i]] += 1;
    }

    int CountTripletsValue = 0;
    std::unordered_map<long, long>::const_iterator FirstProgression;
    std::unordered_map<long, long>::const_iterator SecondProgression;

    for (std::pair<const long, long>& _CurPair : InputMap)
    {
        int CurCountTriplets = _CurPair.second;



        CountTripletsValue += CurCountTriplets;
    }

    return CountTripletsValue;
}


int main()
{
    countTriplets({1,1,1,1,1}, 1);
}
