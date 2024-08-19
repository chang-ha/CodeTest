#include <string>
#include <vector>

using namespace std;

#include <array>

int SearchDataIndex(const std::string& _DataTypeName)
{
	static std::array<std::string, 4> DataType = { "code", "date", "maximum", "remain" };

	for (int i = 0; i < 4; i++)
	{
		std::string _CurDataType = DataType[i];
		if (_DataTypeName == _CurDataType)
		{
			return i;
		}
	}

	// Error
	return -1;
}

#include <algorithm>
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by)
{
	vector<vector<int>> answer;
	// answer의 크기는 최대 data의 크기
	answer.reserve(data.size());

	// 기준이 되는 데이터의 index
	int extIndex = SearchDataIndex(ext);

	for (const std::vector<int>& _CurData : data)
	{
		if (val_ext <= _CurData[extIndex])
		{
			continue;
		}
		answer.push_back(_CurData);
	}

	// sortIndex기준은 sort_by로 결정
	std::sort(answer.begin(), answer.end(), [sortIndex = SearchDataIndex(sort_by)](const std::vector<int>& _Data1, const std::vector<int>& _Data2)
		{
			int Data1_Size = static_cast<int>(_Data1.size());
			int Data2_Size = static_cast<int>(_Data2.size());
			if (Data1_Size != Data2_Size)
			{
				// Error
			}

			if (Data1_Size <= sortIndex ||
				Data2_Size <= sortIndex)
			{
				// Error
			}

			if (_Data1[sortIndex] == _Data2[sortIndex])
			{
				return true;
			}

			return _Data1[sortIndex] < _Data2[sortIndex];
		});

	return answer;
}