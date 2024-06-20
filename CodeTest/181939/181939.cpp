#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) 
{
    int answer = 0;
    std::string A_B = std::to_string(a) + std::to_string(b);
    std::string B_A = std::to_string(b) + std::to_string(a);

    answer = std::stoi(std::max(A_B, B_A));
    return answer;
}