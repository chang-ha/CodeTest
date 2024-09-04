#include <string>

using namespace std;

#include <vector>
#include <stdexcept>
#include <cmath>
int solution(string dartResult)
{
    int answer = 0;
    std::vector<int> Score;
    Score.reserve(3);
    std::vector<char> mOption(3, 0);

    size_t dartResult_size = dartResult.size();
    std::string CheckNumber = "";

    for (size_t i = 0, option_count = -1; i < dartResult_size; i++)
    {
        if (0 != std::isdigit(dartResult[i]))
        {
            CheckNumber += dartResult[i];
        }
        else
        {
            int Pow_Count = 0;
            switch (dartResult[i])
            {
            case 'S':
                Pow_Count = 1;
                break;
            case 'D':
                Pow_Count = 2;
                break;
            case 'T':
                Pow_Count = 3;
                break;
            case '*':
                mOption[option_count] = '*';
                continue;
            case '#':
                mOption[option_count] = '#';
                continue;
            default:
                throw std::invalid_argument("잘못된 문자열이 들어왔습니다.");
            }

            if (" " == CheckNumber)
            {
                throw std::invalid_argument("보너스가 연속으로 들어왔습니다.");
            }

            int Number = std::stoi(CheckNumber);
            int CalcuNum = Number;
            for (int i = 1; i < Pow_Count; i++)
            {
                Number *= CalcuNum;
            }

            Score.push_back(Number);
            CheckNumber = "";
            ++option_count;
        }
    }

    int Score_size = static_cast<int>(Score.size());
    for (int i = Score_size - 1; i >= 0; i--)
    {
        switch (mOption[i])
        {
        case '*':
            if (0 != i)
            {
                Score[i - 1] *= 2;
            }
            Score[i] *= 2;
            break;
        case '#':
            Score[i] *= -1;
            break;
        default:
            break;
        }

        answer += Score[i];
    }

    return answer;
}

// sstream은 사용이 간편하고 가독성이 좋지만 느림
#include <sstream>
int SStreamSolution(std::string dartResult)
{
    int answer = 0;

    std::stringstream DartStream(dartResult);
    std::vector<int> Score;
    Score.reserve(3);

    while (DartStream)
    {
        int ScoreValue = 0;
        char Pow = ' ';
        char Option = ' ';

        DartStream >> ScoreValue;
        DartStream >> Pow;
        DartStream >> Option;

        int Pow_Count = 0;
        switch (Pow)
        {
        case 'S':
            Pow_Count = 1;
            break;
        case 'D':
            Pow_Count = 2;
            break;
        case 'T':
            Pow_Count = 3;
            break;
        default:
            // 잘못된 문자열
            continue;
        }

        int Calcu_Pow = ScoreValue;
        for (int i = 1; i < Pow_Count; i++)
        {
            Calcu_Pow *= ScoreValue;
        }

        switch (Option)
        {
        case '*':
            Calcu_Pow *= 2;
            if (false == Score.empty())
            {
                Score.back() *= 2;
            }
            break;
        case '#':
            Calcu_Pow *= -1;
            break;
        default:
            DartStream.unget();
            break;
        }

        Score.push_back(Calcu_Pow);
    }

    for (const int _CurScore : Score)
    {
        answer += _CurScore;
    }

    return answer;
}