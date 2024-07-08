#include <string>
#include <vector>

using namespace std;

#include <unordered_map>
vector<string> solution(vector<string> players, vector<string> callings)
{
    // players�� ����
    vector<string> answer = players;

    std::unordered_map<string, int> playerMap;

    // unordered_map�� ���� ������ ����
    int i = 0;
    for (std::string _CurPlayer : players)
    {
        playerMap[_CurPlayer] = i;
        ++i;
    }


    for (std::string _CallingPlayer : callings)
    {
        // ȣ��� Player�� ������ ������
        int PlayerRank = playerMap[_CallingPlayer];
        if (0 == PlayerRank)
        {
            // Error
            vector<string> Error;
            return Error;
        }

        // ȣ��Ǵ� Player�� �� ������ ������
        std::string PrevPlayer = answer[PlayerRank - 1];
        // �� Player�� ������ �ڷ�
        playerMap[PrevPlayer] += 1;
        // ȣ��� Player�� ������ ������
        playerMap[_CallingPlayer] -= 1;
        answer[PlayerRank - 1] = _CallingPlayer;
        answer[PlayerRank] = PrevPlayer;
    }

    return answer;
}