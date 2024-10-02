#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/72411

using namespace std;

#include <algorithm>
#include <map>
vector<string> BruteForcesolution(vector<string> orders, vector<int> course)
{
	vector<string> answer;
	const int CourseSize = static_cast<int>(course.size());
	if (0 == CourseSize)
	{
		return {};
	}
	// �ڽ����� - �ֹ� �� ����
	std::map<int, int> MaxCourseValue;

	std::map<std::string, int> CourseCombination;
	// std::next_permutation ���ο��� swap & reverse �ϱ� ������ const �Ұ���
	// ���� : �������� -> ������������ �����ϴ� �˰���
	for (std::string& CurOrder : orders)
	{
		// ���� ����� ��� ���� ���� �� ����
		// ���ο��� a[i - 1] < a[i]�� �����ϴ� ���� ū i���� ã�� ������
		// ���ĵǾ� ���� ������, �߰��� �ش� ���ǿ� �ɸ��� �������� ������ ���ϰ� ��
		std::sort(CurOrder.begin(), CurOrder.end());

		const int CurOrderSize = static_cast<int>(CurOrder.size());
		// course ����� ���� ����
		for (int CourseIndex = 0; CourseIndex < CourseSize; CourseIndex++)
		{
			const int CurCourse = course[CourseIndex];
			if (CurCourse == CurOrderSize)
			{
				CourseCombination[CurOrder] += 1;
				MaxCourseValue[CurCourse] = std::max(CourseCombination[CurOrder], MaxCourseValue[CurCourse]);
			}

			if (CurCourse >= CurOrderSize)
			{
				continue;
			}

			std::vector<bool> CombinationVector(CurOrderSize, false);
			std::fill(CombinationVector.end() - CurCourse, CombinationVector.end(), true);
			// next_permutation�� �ϴ� ������ CurOrder�� �ٲ�� ������
			// do�� ���� ù ��° �������� �����ϰ� next_permutation ����
			// �������� reverse�� ���ֱ� ������ �ٽ� ���� ���·� �ǵ��ƿ� (��, ���ĵǾ����� ������ ���� �ٲ�)
			const size_t CombinationVectorSize = CombinationVector.size();
			do
			{
				std::string CalcuCourse = "";
				for (size_t i = 0; i < CombinationVectorSize; i++)
				{
					if (true == CombinationVector[i])
					{
						CalcuCourse += CurOrder[i];
					}
				}
				CourseCombination[CalcuCourse] += 1;

				MaxCourseValue[CurCourse] = std::max(CourseCombination[CalcuCourse], MaxCourseValue[CurCourse]);
			} while (std::next_permutation(CombinationVector.begin(), CombinationVector.end()));
		}
	}

	for (const std::pair<std::string, int>& CurPair : CourseCombination)
	{
		if (2 > CurPair.second)
		{
			continue;
		}
		const int CurCourseSize = static_cast<int>(CurPair.first.size());
		if (CurPair.second == MaxCourseValue[CurCourseSize])
		{
			answer.push_back(CurPair.first);
		}
	}

	return answer;
}