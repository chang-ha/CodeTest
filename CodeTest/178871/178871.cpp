#include <string>
#include <vector>

using namespace std;

#include <unordered_map>
vector<string> solution(vector<string> players, vector<string> callings)
{
    // players를 복사
    vector<string> answer = players;

    std::unordered_map<string, int> playerMap;

    // unordered_map에 현재 순위를 저장
    int i = 0;
    for (std::string _CurPlayer : players)
    {
        playerMap[_CurPlayer] = i;
        ++i;
    }


    for (std::string _CallingPlayer : callings)
    {
        // 호출된 Player의 순위를 가져옴
        int PlayerRank = playerMap[_CallingPlayer];
        if (0 == PlayerRank)
        {
            // Error
            vector<string> Error;
            return Error;
        }

        // 호출되는 Player의 앞 선수를 가져옴
        std::string PrevPlayer = answer[PlayerRank - 1];
        // 앞 Player의 순위는 뒤로
        playerMap[PrevPlayer] += 1;
        // 호출된 Player의 순위를 앞으로
        playerMap[_CallingPlayer] -= 1;
        answer[PlayerRank - 1] = _CallingPlayer;
        answer[PlayerRank] = PrevPlayer;
    }

    return answer;
}