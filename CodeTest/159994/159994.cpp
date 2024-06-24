#include <string>
#include <vector>

using namespace std;

#include <queue>
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer = "Yes";

    std::queue<std::string> Cards1_Queue;

    for (const std::string& _CurWord : cards1)
    {
        Cards1_Queue.push(_CurWord);
    }

    std::queue<std::string> Cards2_Queue;
    for (const std::string& _CurWord : cards2)
    {
        Cards2_Queue.push(_CurWord);
    }

    for (const std::string& _PopWord : goal)
    {
        if (_PopWord == Cards1_Queue.front())
        {
            Cards1_Queue.pop();
            continue;
        }
        else if (_PopWord == Cards2_Queue.front())
        {
            Cards2_Queue.pop();
            continue;
        }
        else
        {
            answer = "No";
            return answer;
        }
    }

    return answer;
}