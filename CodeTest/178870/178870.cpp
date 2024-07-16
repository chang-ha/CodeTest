#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
	vector<int> answer;

	int StartIndex = 0;
	int EndIndex = 0;
	int SumValue = 0;

	int Sequence_Size = static_cast<int>(sequence.size());
	for (int i = 0; i < Sequence_Size; i++)
	{
		EndIndex = i;
		SumValue += sequence[EndIndex];

		while (k < SumValue)
		{
			SumValue -= sequence[StartIndex];
			++StartIndex;
		}

		if (k != SumValue)
		{
			continue;
		}

		if (answer.empty() ||
			EndIndex - StartIndex < answer[1] - answer[0])
		{
			answer = { StartIndex, EndIndex };
		}
	}

	return answer;
}

#include <limits.h>
vector<int> Otherssolution(vector<int> sequence, int k)
{
	vector<int> answer(2, -1);
	std::vector<std::vector<int>> CalcuVector;

	int SumValue = sequence[0];
	int StartIndex = 0;
	int EndIndex = 0;
	int Sequence_Size = static_cast<int>(sequence.size());

	while (k > SumValue && Sequence_Size > EndIndex + 1)
	{
		++EndIndex;
		SumValue += sequence[EndIndex];
	}

	if (k > SumValue)
	{
		return answer;
	}
	else if (k == SumValue)
	{
		if (Sequence_Size == EndIndex + 1)
		{
			return { StartIndex, EndIndex };
		}
		else
		{
			CalcuVector.push_back({ StartIndex, EndIndex });
		}
	}

	SumValue -= sequence[EndIndex];

	for (int i = EndIndex; i < Sequence_Size; i++)
	{
		int CurValue = sequence[i];
		if (k < CurValue)
		{
			break;
		}

		SumValue = SumValue + CurValue;

		while (k < SumValue && StartIndex != i)
		{
			SumValue -= sequence[StartIndex];
			++StartIndex;
		}

		if (k == SumValue)
		{
			CalcuVector.push_back({ StartIndex, i });
		}
	}

	int MinSize = INT_MAX;
	for (const std::vector<int>& _CurVector : CalcuVector)
	{
		int IndexDiff = _CurVector[1] - _CurVector[0];
		if (MinSize <= IndexDiff)
		{
			continue;
		}
		MinSize = IndexDiff;
		answer = _CurVector;
	}

	return answer;
}