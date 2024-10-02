#include <iostream>
#include <TimeCheck\TimeCheck.h>

#include <string>
#include <vector>

// ����
// https://school.programmers.co.kr/learn/courses/30/lessons/72411

using namespace std;

#include <algorithm>
vector<string> solution(vector<string> orders, vector<int> course)
{
	vector<string> answer;

	// std::next_permutation ���ο��� swap & reverse �ϱ� ������ const �Ұ���
	// ���� : �������� -> ������������ �����ϴ� �˰���
	// ������, --������ �� -> ������ true & ����, ũ�ų� ������ false
	for (std::string& order : orders)
	{
		// ���� ����� ��� ���� ���� �� ����
		// ���ο��� a[i-1] > a[i]�� �����ϴ� ���� ū i���� ã�� ������
		// ���ĵǾ� ���� ������, �߰��� �ش� ���ǿ� �ɸ��� �������� ������ ���ϰ� ��
		std::sort(order.begin(), order.end());
		// next_permutation�� �ϴ� ������ order�� �ٲ�� ������
		// do�� ���� ù ��° �������� �����ϰ� next_permutation ����
		// �������� reverse�� ���ֱ� ������ �ٽ� ���� ���·� �ǵ��ƿ� (��, ���ĵǾ����� ������ ���� �ٲ�)
		do
		{
			std::string::iterator StartIter = order.begin();
			std::string::iterator EndIter = order.end();
			for (; StartIter != EndIter; ++StartIter)
			{
				std::cout << *StartIter;
			}
			std::cout << std::endl;
		} while (std::next_permutation(order.begin(), order.end()));

		std::string::iterator StartIter = order.begin();
		std::string::iterator EndIter = order.end();
		for (; StartIter != EndIter; ++StartIter)
		{
			std::cout << *StartIter;
		}
		std::cout << std::endl;
	}



	return answer;
}

int main() 
{
	solution({ "AFBCG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
	// solution({ {40, 2900},{23, 10000},{11, 5200},{5, 5900},{40, 3100},{27, 9200},{32, 6900} }, { 1300, 1500, 1600, 4900 });
	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT ETime = CheckFunctionTime([&]()
		{
		});

	std::cout << "ATime is " << ATime.count() << " microseconds" << std::endl;
	std::cout << "BTime is " << BTime.count() << " microseconds" << std::endl;
	std::cout << "CTime is " << CTime.count() << " microseconds" << std::endl;
	std::cout << "DTime is " << DTime.count() << " microseconds" << std::endl;
	std::cout << "ETime is " << ETime.count() << " microseconds" << std::endl;
	int x = 0;
}