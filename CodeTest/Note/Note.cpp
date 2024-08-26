#include <TimeCheck\TimeCheck.h>

#include <string>
#include <vector>

using namespace std;

#include <set>
int solution(int n, vector<int> lost, vector<int> reserve)
{
	// sort �� ������ �ߺ����Ÿ� ���� set ���
	std::set<int> lost_set(lost.begin(), lost.end());
	std::set<int> reserve_set(reserve.begin(), reserve.end());

	std::set<int>::const_iterator StartIter = lost_set.begin();
	std::set<int>::const_iterator EndIter = lost_set.end();

	// lost�� reserve�� �ߺ� ����
	for (; StartIter != EndIter;)
	{
		if (0 != reserve_set.erase(*StartIter))
		{
			StartIter = lost_set.erase(StartIter);
			continue;
		}
		++StartIter;
	}

	// ��ü n - lost �л� �� 
	int answer = n - static_cast<int>(lost_set.size());

	vector<bool> Student(n + 1, 1);

	// Student �� lost�� ����� false
	for (const int LostPeople : lost_set)
	{
		Student[LostPeople] = false;
	}

	for (const int BorrowPeople : reserve_set)
	{
		int PrevStudent = BorrowPeople - 1;
		
		// �� ����� �Ҿ���ȴ��� üũ
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

		// �� ����� �Ҿ���ȴ��� üũ
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