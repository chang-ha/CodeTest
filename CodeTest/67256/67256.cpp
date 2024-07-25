#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand)
{
	string answer = "";

	std::vector<std::pair<int, int>> KeyPad;
	KeyPad.resize(10);
	KeyPad[0] = { 3, 1 };
	for (int i = 0; i < 9; i++)
	{
		KeyPad[i + 1] = { i / 3, i % 3 };
	}

	std::pair<int, int> LeftHand = { 3,0 };
	std::pair<int, int> RightHand = { 3,2 };

	for (const int _CurNumber : numbers)
	{
		switch (_CurNumber)
		{
		case 1:
		case 4:
		case 7:
			answer += "L";
			LeftHand = KeyPad[_CurNumber];
			break;
		case 3:
		case 6:
		case 9:
			answer += "R";
			RightHand = KeyPad[_CurNumber];
			break;
		case 2:
		case 5:
		case 8:
		case 0:
		{
			int LeftHandDis = std::abs(LeftHand.first - KeyPad[_CurNumber].first)
				+ std::abs(LeftHand.second - KeyPad[_CurNumber].second);

			int RightHandDis = std::abs(RightHand.first - KeyPad[_CurNumber].first)
				+ std::abs(RightHand.second - KeyPad[_CurNumber].second);

			if (LeftHandDis < RightHandDis)
			{
				answer += "L";
				LeftHand = KeyPad[_CurNumber];
			}
			else if (LeftHandDis > RightHandDis)
			{
				answer += "R";
				RightHand = KeyPad[_CurNumber];
			}
			else if ("left" == hand)
			{
				answer += "L";
				LeftHand = KeyPad[_CurNumber];
			}
			else
			{
				answer += "R";
				RightHand = KeyPad[_CurNumber];
			}
		}
		break;
		}
	}

	return answer;
}