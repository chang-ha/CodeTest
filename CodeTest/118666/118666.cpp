#include <string>
#include <vector>

using namespace std;

#include <unordered_set>
string Vectorsolution(vector<string> survey, vector<int> choices)
{
    size_t Survey_Size = survey.size();
    if (Survey_Size != choices.size())
    {
        return "ERROR";
    }

    string answer = "";
    std::vector<int> Score('Z' - 'A' + 1, 0);

    std::unordered_set<std::string> DebugSet = { "RT", "TR", "FC", "CF", "MJ", "JM", "AN", "NA" };

    for (size_t i = 0; i < Survey_Size; i++)
    {
        if (DebugSet.end() == DebugSet.find(survey[i]))
        {
            // Error
            return "ERROR";
        }

        switch (choices[i])
        {
        case 1:
        case 2:
        case 3:
        case 4:
            Score[survey[i][0] - 'A'] += 4 - choices[i];
            break;
        case 5:
        case 6:
        case 7:
            Score[survey[i][1] - 'A'] += choices[i] - 4;
            break;
        default:
            // Error
            return "ERROR";
            break;
        }
    }

    Score.at('R' - 'A') >= Score.at('T' - 'A') ? answer += 'R' : answer += 'T';
    Score.at('C' - 'A') >= Score.at('F' - 'A') ? answer += 'C' : answer += 'F';
    Score.at('J' - 'A') >= Score.at('M' - 'A') ? answer += 'J' : answer += 'M';
    Score.at('A' - 'A') >= Score.at('N' - 'A') ? answer += 'A' : answer += 'N';

    return answer;
}

#include <map>
string Mapsolution(vector<string> survey, vector<int> choices)
{
    size_t Survey_Size = survey.size();
    if (Survey_Size != choices.size())
    {
        return "ERROR";
    }

    string answer = "";

    std::unordered_set<std::string> DebugSet = { "RT", "TR", "FC", "CF", "MJ", "JM", "AN", "NA" };

    std::map<char, int> MBTIMap;

    for (size_t i = 0; i < Survey_Size; i++)
    {
        if (DebugSet.end() == DebugSet.find(survey[i]))
        {
            // Error
            return "ERROR";
        }

        if (4 >= choices[i])
        {
            MBTIMap[survey[i][0]] += 4 - choices[i];
        }
        else
        {
            MBTIMap[survey[i][1]] += choices[i] - 4;
        }
    }

    std::vector<std::vector<char>> MBTIVector = { {'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'} };

    for (size_t i = 0; i < 4; i++)
    {
        const char LeftMBTIChar = MBTIVector[i][0];
        const char RightMBTIChar = MBTIVector[i][1];
        MBTIMap[LeftMBTIChar] >= MBTIMap[RightMBTIChar] ? answer += LeftMBTIChar : answer += RightMBTIChar;
    }

    return answer;
}