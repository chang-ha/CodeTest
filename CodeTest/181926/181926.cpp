#include <string>
#include <vector>

using namespace std;

int Swtichsolution(int n, string control)
{
    int answer = n;

    for (const char _CurInput : control)
    {
        switch (_CurInput)
        {
        case 'w':
            answer += 1;
            break;
        case 's':
            answer += -1;
            break;
        case 'd':
            answer += 10;
            break;
        case 'a':
            answer -= 10;
            break;
        default:
            break;
        }
    }

    return answer;
}

int Vectorsolution(int n, string control)
{
    int answer = n;

    std::vector<int> Control_Vector('z' - 'a' + 1, 0);
    Control_Vector['w' - 'a'] = 1;
    Control_Vector['s' - 'a'] = -1;
    Control_Vector['d' - 'a'] = 10;
    Control_Vector['a' - 'a'] = -10;

    for (const char _CurInput : control)
    {
        answer += Control_Vector[_CurInput - 'a'];
    }

    return answer;
}