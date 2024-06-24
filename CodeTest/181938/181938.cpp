#include <string>
#include <vector>

using namespace std;

int solution(int a, int b)
{
    int answer = 2 * a * b;
    std::string AnswerString = std::to_string(a) + std::to_string(b);

    answer = std::max(answer, std::stoi(AnswerString));

    return answer;
}