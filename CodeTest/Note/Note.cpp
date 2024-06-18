#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;
    answer.resize(2, -1);

    size_t Park_ColSize = park.size();
    for (size_t Start_YPos = 0; Start_YPos < Park_ColSize; Start_YPos++)
    {
        size_t Start_XPos = park[Start_YPos].find_first_of("S");
        if (std::string::npos == Start_XPos)
        {
            continue;
        }

        size_t Check_Another_S = park[Start_YPos].find_last_of("S");
        if (Check_Another_S != Start_XPos)
        {
            // Error
            return answer;
        }

        if (-1 == answer[0])
        {
            answer[0] = static_cast<int>(Start_YPos);
            answer[1] = static_cast<int>(Start_XPos);
        }
        else
        {
            // Error
            return answer;
        }
    }

    vector<int> DestinationPos(2);
    for (const std::string& _CurRoute : routes)
    {
        short MoveDir_Row = 0;
        short MoveDir_Col = 0;
        switch (_CurRoute[0])
        {
        case 'N':
            MoveDir_Col = -1;
            break;
        case 'S':
            MoveDir_Col = 1;
            break;
        case 'W':
            MoveDir_Row = -1;
            break;
        case 'E':
            MoveDir_Row = 1;
            break;
        default:
            // Error
            return answer;
        }
        std::string MoveString = _CurRoute.substr(2);

        int MoveCount = std::stoi(MoveString);
        DestinationPos[0] = answer[0] + MoveCount * MoveDir_Col;
        DestinationPos[1] = answer[1] + MoveCount * MoveDir_Row;

        if (Park_ColSize <= DestinationPos[0] || 0 > DestinationPos[0])
        {
            continue;
        }

        if (static_cast<int>(park[answer[0]].size()) <= DestinationPos[1] || 0 > DestinationPos[1])
        {
            continue;
        }

        for (int i = 1; i <= MoveCount; i++)
        {
            char CurChar = park[answer[0] + i * MoveDir_Col][answer[1] + i * MoveDir_Row];
            if ('X' == CurChar)
            {
                DestinationPos = answer;
                break;
            }
        }

        answer = DestinationPos;
    }

    return answer;
}

int main()
{
    solution({ "SXOOO", "OXOOO", "OOOOO" }, {"E 3", "S 1", "W 1", "N 2"});
}
