#include <string>
#include <vector>

using namespace std;

#include <numeric>
vector<int> solution(int start_num, int end_num) 
{
    vector<int> answer(end_num - start_num + 1);
    std::iota(answer.begin(), answer.end(), start_num);
    return answer;
