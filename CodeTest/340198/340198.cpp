#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/340198

using namespace std;

#include <algorithm>
#include <unordered_set>
int solution(vector<int> mats, vector<vector<string>> park)
{
	int answer = -1;
	// ���ڸ� ū ������ ����
	std::sort(mats.begin(), mats.end(), greater<int>());

	const size_t Col_park_size = park.size();

	if (0 == Col_park_size)
	{
		// Error
		return answer;
	}

	const size_t Row_park_size = park[0].size();

	if (0 == Row_park_size)
	{
		// Error
		return answer;
	}

	// ������ ���ڸ� ũ�� set�� ����
	std::unordered_set<int> MatSet;

	// ������ ���ڸ� ���� vector
	std::vector<std::vector<int>> MatVector(Col_park_size, std::vector<int>(Row_park_size, 0));
	for (size_t i = 0; i < Col_park_size; i++)
	{
		for (size_t j = 0; j < Row_park_size; j++)
		{
			if ("-1" == park[i][j])
			{
				MatVector[i][j] = 1;
			}
		}
	}

	for (size_t i = 1; i < Col_park_size; i++)
	{
		for (size_t j = 1; j < Row_park_size; j++)
		{
			// ���� ��ġ�� 0�̸� (�ٸ� ���ڸ� ����) continue;
			if (0 == MatVector[i][j])
			{
				continue;
			}

			// �밢��, ��, �� �� ���� ���� �� + 1 ����
			MatVector[i][j] =
				std::min({
				MatVector[i - 1][j - 1] ,
				MatVector[i][j - 1],
				MatVector[i - 1][j] }) + 1;

			// ���� �� set�� ����
			MatSet.insert(MatVector[i][j]);
		}
	}

	// for�� ���鼭 set�� ���ڸ� ũ�� ��
	for (const int MatrixValue : mats)
	{
		if (MatSet.end() != MatSet.find(MatrixValue))
		{
			return MatrixValue;
		}
	}

	return answer;
}