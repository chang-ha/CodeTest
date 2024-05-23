#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */


// priority_queue
//int FindMedian(const vector<int>& _Vector)
//{
//	std::priority_queue<int, vector<int>, greater<int>> Min_Heap;
//	std::priority_queue<int, vector<int>, less<int>> Max_Heap;
//
//	size_t VectorSize = _Vector.size();
//	for (size_t i = 0; i < VectorSize; i++)
//	{
//		int CurValue = _Vector[i];
//
//		if (true == Max_Heap.empty())
//		{
//			Max_Heap.emplace(CurValue);
//			continue;
//		}
//
//		if (Max_Heap.top() > CurValue)
//		{
//			Max_Heap.emplace(CurValue);
//		}
//		else
//		{
//			Min_Heap.emplace(CurValue);
//		}
//
//		if (Max_Heap.size() < Min_Heap.size())
//		{
//			Max_Heap.push(Min_Heap.top());
//			Min_Heap.pop();
//		}
//		else if (Max_Heap.size() - 1 > Min_Heap.size())
//		{
//			Min_Heap.push(Max_Heap.top());
//			Max_Heap.pop();
//		}
//	}
//
//	int Result = -1;
//
//	if (0 == VectorSize % 2)
//	{
//		Result = (Max_Heap.top() + Min_Heap.top());
//	}
//	else
//	{
//		Result = Max_Heap.top() * 2;
//	}
//
//	return Result;
//}
//
//int activityNotifications(const vector<int>& expenditure, int d)
//{
//	int NotifyNumber = 0;
//	int InputVectorSize = static_cast<int>(expenditure.size());
//
//	if (d + 1 > InputVectorSize || 0 >= d)
//	{
//		return NotifyNumber;
//	}
//
//	std::vector<int> CompareVector(d);
//	std::vector<int> SortingVector(d);
//	int MedianValue = -1;
//	std::copy(expenditure.begin(), expenditure.begin() + d, CompareVector.begin());
//	int CurMoney = -1;
//	for (int i = 0; i < InputVectorSize - d; i++)
//	{
//		MedianValue = FindMedian(CompareVector);
//		CurMoney = expenditure[i + d];
//		if (CurMoney >= MedianValue)
//		{
//			++NotifyNumber;
//		}
//		CompareVector[i % d] = CurMoney;
//	}
//
//	return NotifyNumber;
//}


// Copy & Sort
//int activityNotifications(vector<int> expenditure, int d) 
//{
//    int NotifyNumber = 0;
//    int InputVectorSize = static_cast<int>(expenditure.size());
//
//    if (d + 1 > InputVectorSize)
//    {
//        return NotifyNumber;
//    }
//
//    std::vector<int> CompareVector(d);
//    int MediumValue = -1;
//
//    for (int i = 0; i < InputVectorSize - d; i++)
//    {
//        std::copy(expenditure.begin() + i, expenditure.begin() + i + d, CompareVector.begin());
//        std::sort(CompareVector.begin(), CompareVector.end());
//
//        switch (d % 2)
//        {
//        case 0:
//            MediumValue = (CompareVector[d / 2 - 1] + CompareVector[d / 2]);
//            break;
//        case 1:
//            MediumValue = CompareVector[d / 2] * 2;
//            break;
//        }
//
//        int CurSpendMoney = expenditure[i + d];
//        if (CurSpendMoney >= MediumValue)
//        {
//            ++NotifyNumber;
//        }
//    }
//
//    return NotifyNumber;
//}

// Counting Sort
int GetDoubleMedian(const std::vector<int>& _CountingSortVector, int d)
{
    int DoubleMedian = 0;
    int Count = 0;
    int InputVectorSize = static_cast<int>(_CountingSortVector.size());

    switch (d % 2)
    {
    case 0:
    {
        // d / 2
        // d / 2 + 1
        for (int i = 0; i < InputVectorSize; i++)
        {
            Count += _CountingSortVector[i];
            if (0 == DoubleMedian && d / 2 <= Count)
            {
                DoubleMedian += i;
            }

            if (d / 2 + 1 <= Count)
            {
                DoubleMedian += i;
                break;
            }
        }
        break;
    }
    case 1:
    {
        // d / 2
        for (int i = 0; i < InputVectorSize; i++)
        {
            Count += _CountingSortVector[i];
            if (d / 2 < Count)
            {
                DoubleMedian = i * 2;
                break;
            }
        }
        break;
    }
    }
    return DoubleMedian;
}

int activityNotifications(const std::vector<int>& expenditure, int d)
{
    int NotifyNumber = 0;
    int InputVectorSize = static_cast<int>(expenditure.size());
    
    if (d + 1 > InputVectorSize)
    {
        return NotifyNumber;
    }

    std::vector<int> CountingSortVector(201); // 0 <= expenditure[i] <= 200

    for (int i = 0; i < d; i++)
    {
        ++CountingSortVector[expenditure[i]];
    }

    for (int i = d; i < InputVectorSize; i++)
    {
        int DoubleMedian = GetDoubleMedian(CountingSortVector, d);
        
        int CurSpendMoney = expenditure[i];
        if (CurSpendMoney >= DoubleMedian)
        {
            ++NotifyNumber;
        }

        --CountingSortVector[expenditure[i - d]];
        ++CountingSortVector[CurSpendMoney];
    }

    return NotifyNumber;
}

int main()
{
    activityNotifications({ 2,3,4,2,3,6,8,4,5 }, 5);

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
