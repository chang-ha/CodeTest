#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) 
{
    string answer = phone_number;

    const size_t blur_size = answer.size() - 4;

    answer.replace(answer.begin(), answer.begin() + blur_size, std::string(blur_size, '*'));

    return answer;
}