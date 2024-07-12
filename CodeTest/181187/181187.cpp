#include <string>
#include <vector>
#include <cmath>

using namespace std;
long long solution(int r1, int r2)
{
    long long answer = 0;
    long long L_r1 = static_cast<long long>(r1);
    long long L_r2 = static_cast<long long>(r2);

    long long Max_Square = L_r2 * L_r2;
    long long Min_Square = L_r1 * L_r1;
    for (long long x = 1; x <= L_r2; x++)
    {
        long long x_Square = x * x;
        long long MinValue = static_cast<long long>(std::ceil(std::sqrt(Min_Square - x_Square)));
        long long MaxValue = static_cast<long long>(std::floor(std::sqrt(Max_Square - x_Square)));

        answer += (MaxValue - MinValue + 1);
    }

    answer *= 4;

    return answer;
}

long long VerySlowsolution(int r1, int r2)
{
    long long answer = 0;

    double MinRadius = r1 * r1;
    double MaxRadius = r2 * r2;
    for (int y = 0; y < r2; y++)
    {
        double Radius = 0;

        for (int x = 0; x < r2; x++)
        {
            Radius = x * x + y * y;

            if (MaxRadius > Radius && MinRadius < Radius)
            {
                if (0 == x || 0 == y)
                {
                    answer += 2;
                }
                else
                {
                    answer += 4;
                }
            }
        }
    }

    return answer;
}

long long VeryVerySlowsolution(int r1, int r2) 
{
    long long answer = 0;

    double MinRadius = r1 * r1;
    double MaxRadius = r2 * r2;
    for (int y = -r2; y < r2; y++)
    {
        double Radius = 0;

        for (int x = -r2; x < r2; x++)
        {
            Radius = x * x + y * y;

            if (MaxRadius > Radius && MinRadius < Radius)
            {
                answer += 1;
            }
        }
    }

    return answer;
}