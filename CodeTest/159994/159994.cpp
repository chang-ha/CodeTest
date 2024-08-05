#include <string>
#include <vector>

using namespace std;

string Vectorsolution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer = "Yes";

    int Cards1_Index = 0;
    int Cards2_Index = 0;

    for (const std::string& _CurWord : goal)
    {
        if (_CurWord == cards1[Cards1_Index])
        {
            ++Cards1_Index;
        }
        else if (_CurWord == cards2[Cards2_Index])
        {
            ++Cards2_Index;
        }
        else
        {
            answer = "No";
            return answer;
        }
    }

    return answer;
}

#include <queue>
string Queuesolution(vector<string> cards1, vector<string> cards2, vector<string> goal)
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
        if (false == Cards1_Queue.empty() 
            && _PopWord == Cards1_Queue.front())
        {
            Cards1_Queue.pop();
            continue;
        }
        else if (false == Cards1_Queue.empty()
            && _PopWord == Cards2_Queue.front())
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