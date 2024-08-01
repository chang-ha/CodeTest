using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = money - static_cast<long long>(price) * count * (count + 1) / 2;

    if (answer > 0)
    {
        answer = 0;
    }
    else
    {
        answer *= -1;
    }

    return answer;
}

long long solution(int price, int money, int count)
{
    long long RequireMoney = static_cast<long long>(price) * count * (count + 1) / 2;
    return money < RequireMoney ? RequireMoney - money : 0;
}