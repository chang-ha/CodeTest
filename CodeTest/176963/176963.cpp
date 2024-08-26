#include <string>
#include <vector>

using namespace std;

#include <unordered_map>
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer;

    // 이름과 점수 사이즈 차이 존재시 에러
    size_t yearning_size = yearning.size();
    if (yearning_size != name.size())
    {
        // Error
        return answer;
    }

    // 이름과 점수 매핑
    std::unordered_map<std::string, int> MemoryScore;
    for (size_t i = 0; i < yearning_size; i++)
    {
        MemoryScore[name[i]] = yearning[i];
    }

    size_t photo_size = photo.size();
    answer.resize(photo_size);
    for (size_t i = 0; i < photo_size; i++)
    {
        int memory = 0;

        // 현재 사진의 점수 계산
        const std::vector<string>& _CurPhoto = photo[i];
        for (const std::string& _CurName : _CurPhoto)
        {
            std::unordered_map<std::string, int>::const_iterator _CurMemoryScore = MemoryScore.find(_CurName);
            if (MemoryScore.end() == _CurMemoryScore)
            {
                // 이름이 없으면 continue
                continue;
            }

            // 있으면 점수에 합산
            memory += _CurMemoryScore->second;
        }

        answer[i] = memory;
    }

    return answer;
}