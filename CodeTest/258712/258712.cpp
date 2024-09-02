#include <string>
#include <vector>

using namespace std;

#include <unordered_map>
#include <numeric>
#include <stdexcept>
int solution(vector<string> friends, vector<string> gifts)
{
    int answer = 0;

    std::unordered_map<std::string, int> Friends_Index;

    const int Friends_Size = static_cast<int>(friends.size());
    for (int i = 0; i < Friends_Size; i++)
    {
        // 친구들의 이름과 순서 매핑
        Friends_Index[friends[i]] = i;
    }

    std::vector<std::vector<int>> GiftVector(Friends_Size);
    for (std::vector<int>& _CurVector : GiftVector)
    {
        _CurVector.resize(Friends_Size);
    }

    for (const std::string& _CurGift : gifts)
    {
        // 빈칸을 기준으로 이름 나눔
        size_t BlankSpace = _CurGift.find_first_of(" ");

        if (std::string::npos == BlankSpace)
        {
            // Error
            throw std::runtime_error("이름을 공백 기준으로 나눠야합니다.");
            return -1;
        }

        // 주는사람
        std::string GiftGiver = _CurGift.substr(0, BlankSpace);
        // 받는사람
        std::string GiftReceiver = _CurGift.substr(BlankSpace + 1);

        if (Friends_Index.end() == Friends_Index.find(GiftGiver) ||
            Friends_Index.end() == Friends_Index.find(GiftReceiver))
        {
            // Error
            throw std::runtime_error("친구 명단에 존재하지 않습니다.");
            return -1;
        }

        GiftVector[Friends_Index[GiftGiver]][Friends_Index[GiftReceiver]] += 1;
    }

    std::vector<int> GiftScore(Friends_Size);

    // 선물 지수 계산
    for (int i = 0; i < Friends_Size; i++)
    {
        // 준 선물 계산
        GiftScore[i] = std::accumulate(GiftVector[i].begin(), GiftVector[i].end(), 0);
        for (int j = 0; j < Friends_Size; j++)
        {
            // 받은 선물 차감
            GiftScore[i] -= GiftVector[j][i];
        }
    }

    for (int GiverIndex = 0; GiverIndex < Friends_Size; GiverIndex++)
    {
        int ExpectGift = 0;
        for (int ReceiverIndex = 0; ReceiverIndex < Friends_Size; ReceiverIndex++)
        {
            if (GiverIndex == ReceiverIndex)
            {
                continue;
            }

            int GiveValue = GiftVector[GiverIndex][ReceiverIndex];
            int ReceiveValue = GiftVector[ReceiverIndex][GiverIndex];
            // 더 많은 선물 준사람 
            if (GiveValue > ReceiveValue)
            {
                ExpectGift += 1;
            }
            // 선물 지수가 더 높은사람
            else if (GiveValue == ReceiveValue && GiftScore[GiverIndex] > GiftScore[ReceiverIndex])
            {
                ExpectGift += 1;
            }
        }
        // 선물을 가장 많이 받는 숫자
        answer = std::max(answer, ExpectGift);
    }

    return answer;
}
