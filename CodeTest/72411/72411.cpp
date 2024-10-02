#include <string>
#include <vector>

// 문제
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
	// 코스길이 - 주문 수 매핑
	std::map<int, int> MaxCourseValue;

	std::map<std::string, int> CourseCombination;
	// std::next_permutation 내부에서 swap & reverse 하기 때문에 const 불가능
	// 원리 : 오름차순 -> 내림차순으로 변경하는 알고리즘
	for (std::string& CurOrder : orders)
	{
		// 정렬 해줘야 모든 순열 구할 수 있음
		// 내부에서 a[i - 1] < a[i]을 만족하는 가장 큰 i값을 찾기 때문에
		// 정렬되어 있지 않으면, 중간에 해당 조건에 걸리는 순간부터 순열을 구하게 됨
		std::sort(CurOrder.begin(), CurOrder.end());

		const int CurOrderSize = static_cast<int>(CurOrder.size());
		// course 수대로 조합 구함
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
			// next_permutation을 하는 순간에 CurOrder가 바뀌기 때문에
			// do로 가장 첫 번째 조합으로 실행하고 next_permutation 실행
			// 마지막에 reverse를 해주기 때문에 다시 원래 형태로 되돌아옴 (단, 정렬되어있지 않으면 형태 바뀜)
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