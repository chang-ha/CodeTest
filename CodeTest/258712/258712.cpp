#include <string>
#include <vector>

using namespace std;

#include <unordered_map>
#include <numeric>
int solution(vector<string> friends, vector<string> gifts)
{
    int answer = 0;

    std::unordered_map<std::string, int > Friends_Index;

    int Friends_Size = static_cast<int>(friends.size());
    for (int i = 0; i < Friends_Size; i++)
    {
        Friends_Index[friends[i]] = i;
    }

    std::vector<std::vector<int>> GiftVector(Friends_Size);
    for (std::vector<int>& _CurVector : GiftVector)
    {
        _CurVector.resize(Friends_Size);
    }

    for (const std::string& _CurGift : gifts)
    {
        size_t BlankSpace = _CurGift.find_first_of(" ");

        if (std::string::npos == BlankSpace)
        {
            // Error
            return -1;
        }

        std::string GiftGiver = _CurGift.substr(0, BlankSpace);
        std::string GiftReceiver = _CurGift.substr(BlankSpace + 1);

        if (Friends_Index.end() == Friends_Index.find(GiftGiver) ||
            Friends_Index.end() == Friends_Index.find(GiftReceiver))
        {
            // Error
            return -1;
        }

        GiftVector[Friends_Index[GiftGiver]][Friends_Index[GiftReceiver]] += 1;
    }

    std::vector<int> GiftScore(Friends_Size);

    for (int i = 0; i < Friends_Size; i++)
    {
        GiftScore[i] = std::accumulate(GiftVector[i].begin(), GiftVector[i].end(), 0);
        for (int j = 0; j < Friends_Size; j++)
        {
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
            if (GiveValue > ReceiveValue)
            {
                ExpectGift += 1;
            }
            else if (GiveValue == ReceiveValue && GiftScore[GiverIndex] > GiftScore[ReceiverIndex])
            {
                ExpectGift += 1;
            }
        }
        answer = std::max(answer, ExpectGift);
    }

    return answer;
}
