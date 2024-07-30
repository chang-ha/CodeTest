#include <string>
#include <vector>

using namespace std;

#include <algorithm>
string solution(string my_string, int s, int e) 
{
    string answer = my_string;
    std::reverse(answer.begin() + s , answer.begin() + e + 1);
    return answer;
}