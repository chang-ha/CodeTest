#include <TimeCheck\TimeCheck.h>

#include <string>
#include <vector>

using namespace std;

#include <set>
int solution(int n, vector<int> lost, vector<int> reserve)
{
	// sort 및 원할한 중복제거를 위한 set 사용
	std::set<int> lost_set(lost.begin(), lost.end());
	std::set<int> reserve_set(reserve.begin(), reserve.end());

	std::set<int>::const_iterator StartIter = lost_set.begin();
	std::set<int>::const_iterator EndIter = lost_set.end();

	// lost와 reserve의 중복 제거
	for (; StartIter != EndIter;)
	{
		if (0 != reserve_set.erase(*StartIter))
		{
			StartIter = lost_set.erase(StartIter);
			continue;
		}
		++StartIter;
	}

	// 전체 n - lost 학생 수 
	int answer = n - static_cast<int>(lost_set.size());

	vector<bool> Student(n + 1, 1);

	// Student 중 lost인 사람을 false
	for (const int LostPeople : lost_set)
	{
		Student[LostPeople] = false;
	}

	for (const int BorrowPeople : reserve_set)
	{
		int PrevStudent = BorrowPeople - 1;
		
		// 앞 사람이 잃어버렸는지 체크
		if (false == Student[PrevStudent])
		{
			++answer;
			Student[PrevStudent] = true;
			continue;
		}

		int NextStudent = BorrowPeople + 1;
		if (n < NextStudent)
		{
			break;
		}

		// 뒷 사람이 잃어버렸는지 체크
		if (false == Student[NextStudent])
		{
			++answer;
			Student[NextStudent] = true;
		}
	}

	return answer;
}

int main()
{
	solution(3, {1,2,3}, {1,2,3});
	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
		});


	TIME_UNIT ETime = CheckFunctionTime([&]()
		{
		});


	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
		});
	int x = 0;
}