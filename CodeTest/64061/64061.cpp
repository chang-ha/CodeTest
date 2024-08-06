#include <string>
#include <vector>

using namespace std;

int PushBasket(vector<int>& _Basket, int _DollNumber)
{
    if (true == _Basket.empty() || _Basket.back() != _DollNumber)
    {
        _Basket.push_back(_DollNumber);
        return 0;
    }
    else
    {
        _Basket.pop_back();
        return 2;
    }
}

#include <map>
int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    std::vector<int> Basket;
    int Y_Length = static_cast<int>(board.size());
    Basket.reserve(Y_Length);

    std::map<int, int> DollPosition;

    for (int _CurMove : moves)
    {
        if (0 >= _CurMove || Y_Length < _CurMove)
        {
            // Error
            return 0;
        }
        _CurMove -= 1;

        std::map<int, int>::const_iterator FindIter = DollPosition.find(_CurMove);
        if (DollPosition.end() != FindIter)
        {
            int Depth = FindIter->second;
            if (Y_Length != Depth)
            {
                answer += PushBasket(Basket, board[Depth][_CurMove]);
                DollPosition[_CurMove] += 1;
            }
            continue;
        }

        for (int i = 0; i < Y_Length; i++)
        {
            int DollNumber = board[i][_CurMove];
            if (0 == DollNumber)
            {
                continue;
            }

            answer += PushBasket(Basket, DollNumber);
            DollPosition[_CurMove] = i + 1;
            break;
        }
    }

    return answer;
}
