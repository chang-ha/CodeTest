#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b)
{
    long long answer = 0;
    long long L_a = static_cast<long long>(a);
    long long L_b = static_cast<long long>(b);

    if (L_a == L_b)
    {
        return L_a;
    }

    answer = (L_a + L_b) * (std::abs(L_a - L_b) + 1) / 2;

    return answer;
}

//long long OverFlowsolution(int a, int b)
//{
//    long long answer = 0;
//
//    if (a == b)
//    {
//        return a;
//    }
//
//    // OverFlow ¹ß»ý
//    answer = (a + b) * (std::abs(a - b) + 1) / 2;
//
//    return answer;
//}

// #include <numeric>
// long long Vectorsolution(int a, int b)
// {
//     long long answer = 0;
// 
//     if (a == b)
//     {
//         return a;
//     }
// 
//     vector<int> RangeVector(b - a + 1);
//     std::iota(RangeVector.begin(), RangeVector.end(), a);
//     answer = std::accumulate(RangeVector.begin(), RangeVector.end(), 0);
// 
//     return answer;
// }