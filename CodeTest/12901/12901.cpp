#include <string>
#include <vector>

using namespace std;
string Switchsolution(int a, int b)
{
	string answer = "";

	int SumDay = 0;

	for (int i = 1; i <= a; i++)
	{
		switch (i)
		{
		case 1:
			break;
		case 3:
			SumDay += 29;
			break;
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			SumDay += 31;
			break;
		case 5:
		case 7:
		case 10:
		case 12:
			SumDay += 30;
			break;
		default:
			// 존재하지 않는 달
			return "Wrong Month";
			break;
		}
	}

	SumDay += b;

	switch (SumDay % 7)
	{
	case 0:
		answer = "THU";
		break;
	case 1:
		answer = "FRI";
		break;
	case 2:
		answer = "SAT";
		break;
	case 3:
		answer = "SUN";
		break;
	case 4:
		answer = "MON";
		break;
	case 5:
		answer = "TUE";
		break;
	case 6:
		answer = "WED";
		break;
	default:
		// Error
		return "Impossible Result";
		break;
	}

	return answer;
}

string Vectorsolution(int a, int b)
{
	std::vector<int> Month = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	std::vector<std::string> Day = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
	int SumDay = 0;

	for (int i = 0; i < a - 1; i++)
	{
		SumDay += Month[i];
	}
	SumDay += b;

	return Day[SumDay % 7];
}