#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/92341

using namespace std;

#include <stdexcept>
int CalcuTime(const std::string& InTime)
{
	const size_t DividePos = InTime.find_first_of(':');
	const size_t DividePos2 = InTime.find_last_of(':');
	if (5 != InTime.size() || DividePos != DividePos2)
	{
		throw std::invalid_argument("Wrong Input Time");
	}

	const int Hour = std::stoi(InTime.substr(0, DividePos));
	const int Minute = std::stoi(InTime.substr(DividePos + 1));

	return Hour * 60 + Minute;
}

#include <sstream>
#include <map>
vector<int> solution(vector<int> fees, vector<string> records)
{
	if (4 != fees.size() || 0 >= fees[2])
	{
		return {};
	}

	std::map<int, std::pair<int, bool>> CarHistory;
	for (const std::string& CurRecord : records)
	{
		const size_t CurRecordSize = CurRecord.size();
		if (13 != CurRecordSize && 14 != CurRecordSize)
		{
			throw std::invalid_argument("Wrong records Input");
		}

		std::stringstream Record(CurRecord);
		std::string Time, CarNumber, History = "";

		Record >> Time;
		Record >> CarNumber;
		Record >> History;

		const int iCarNumber = std::stoi(CarNumber);
		const bool bIn = History == "IN" ? true : false;

		std::map<const int, std::pair<int, bool>>::iterator FindIter = CarHistory.find(iCarNumber);
		if (CarHistory.end() == FindIter || false == CarHistory[iCarNumber].second)
		{
			// In
			CarHistory[iCarNumber].first = CalcuTime(Time) - CarHistory[iCarNumber].first;
			CarHistory[iCarNumber].second = true;
		}
		else
		{
			switch (bIn)
			{
			case false:
				// Out
				CarHistory[iCarNumber].first = CalcuTime(Time) - CarHistory[iCarNumber].first;
				CarHistory[iCarNumber].second = false;
				break;
			case true:
				// Double In
				throw std::invalid_argument("Double In History");
			}
		}
	}

	const int MaximumTime = CalcuTime("23:59");
	vector<int> answer;
	answer.reserve(CarHistory.size());
	for (std::pair<const int, std::pair<int, bool>>& CurPair : CarHistory)
	{
		if (true == CurPair.second.second)
		{
			// Remain Car
			CurPair.second.first = MaximumTime - CurPair.second.first;
		}

		CurPair.second.first -= fees[0];
		answer.push_back(fees[1]);

		if (0 < CurPair.second.first)
		{
			int Quotient = CurPair.second.first / fees[2];
			const int Remain = CurPair.second.first % fees[2];
			Quotient += Remain == 0 ? 0 : 1;

			answer.back() += Quotient * fees[3];
		}
	}

	return answer;
}