#include <string>
#include <vector>

using namespace std;

int ForLoopsolution(vector<int> num_list)
{
	int answer = 0;

	int OddNum = 0;
	int EvenNum = 0;
	int OddDigit = 1;
	int EvenDigit = 1;

	int Num_Size = static_cast<int>(num_list.size());
	for (int i = Num_Size - 1; i >= 0; i--)
	{
		switch (num_list[i] % 2)
		{
		case 0:
			EvenNum += EvenDigit * num_list[i];
			EvenDigit *= 10;
			break;
		case 1:
			OddNum += OddDigit * num_list[i];
			OddDigit *= 10;
			break;
		default:
			// Error
			break;
		}
	}

	answer = OddNum + EvenNum;
	return answer;
}

int Iteratorsolution(vector<int> num_list)
{
	int answer = 0;

	int OddNum = 0;
	int EvenNum = 0;
	int OddDigit = 1;
	int EvenDigit = 1;

	std::vector<int>::const_reverse_iterator StartIter = num_list.rbegin();
	std::vector<int>::const_reverse_iterator EndIter = num_list.rend();
	for (; StartIter != EndIter;)
	{
		switch (*StartIter % 2)
		{
		case 0:
			EvenNum += EvenDigit * *StartIter;
			EvenDigit *= 10;
			break;
		case 1:
			OddNum += OddDigit * *StartIter;
			OddDigit *= 10;
			break;
		default:
			// Error
			break;
		}
		++StartIter;
	}

	answer = OddNum + EvenNum;
	return answer;
}

int Otherssolution(vector<int> num_list)
{
	int answer = 0;

	int OddNum = 0;
	int EvenNum = 0;

	int Num_Size = static_cast<int>(num_list.size());
	for (int i = Num_Size - 1; i >= 0; i--)
	{
		switch (num_list[i] % 2)
		{
		case 0:
			EvenNum *= 10;
			EvenNum += num_list[i];
			break;
		case 1:
			OddNum *= 10;
			OddNum += num_list[i];
			break;
		default:
			// Error
			break;
		}
	}

	answer = OddNum + EvenNum;
	return answer;
}