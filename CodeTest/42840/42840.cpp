#include <string>
#include <vector>

using namespace std;

#include <algorithm>
#include <array>
vector<int> solution(vector<int> answers) 
{
    static std::array<int, 5> FirstPerson = { 1,2,3,4,5 };
    static std::array<int, 8> SecondPerson = { 2,1,2,3,2,4,2,5 };
    static std::array<int, 10> ThirdPerson = { 3,3,1,1,2,2,4,4,5,5 };

    vector<int> answer;
    answer.reserve(3);

    vector<int> AnswerCount(3, 0);

    const size_t answers_size = answers.size();
    for (size_t i = 0; i < answers_size; i++)
    {
        const int CurAnswer = answers[i];
        AnswerCount[0] += CurAnswer == FirstPerson[i % 5] ? 1 : 0;
        AnswerCount[1] += CurAnswer == SecondPerson[i % 8] ? 1 : 0;
        AnswerCount[2] += CurAnswer == ThirdPerson[i % 10] ? 1 : 0;
    }

    const int MaxAnswerCount = *std::max_element(AnswerCount.begin(), AnswerCount.end());

    const size_t AnswerCount_size = AnswerCount.size();
    for (size_t i = 0; i < AnswerCount_size; i++)
    {
        if (MaxAnswerCount == AnswerCount[i])
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}