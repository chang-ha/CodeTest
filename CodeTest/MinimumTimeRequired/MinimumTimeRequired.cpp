#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Use Class
// TLE
//
//#include <string>
//#include <vector>
//
//long minTime(vector<long> machines, long goal);
//
//class Machine
//{
//	friend long minTime(vector<long> machines, long goal);
//
//	Machine() = delete;
//	Machine(int _RequireDay)
//		: RequireDay(_RequireDay)
//	{
//
//	}
//
//	int RequireDay = 0;
//	int CurDay = 0;
//	static int Goal;
//
//	static void SetGoal(int _Goal)
//	{
//		Goal = _Goal;
//	}
//
//	void Work()
//	{
//		++CurDay;
//		if (CurDay >= RequireDay)
//		{
//			CurDay = 0;
//			--Goal;
//		}
//
//	}
//};
//
//int main()
//{
//	TIME_UNIT ATime = CheckFunctionTime([&]()
//		{
//			minTime({ 4,5,6 }, 12);
//		});
//
//	TIME_UNIT BTime = CheckFunctionTime([&]()
//		{
//		});
//
//	int a = 0;
//}
//
//int Machine::Goal = 0;
//
//long minTime(vector<long> machines, long goal)
//{
//	vector<Machine*> Machines;
//	Machines.reserve(machines.size());
//	for (const long _CurMachine : machines)
//	{
//		Machines.push_back(new Machine(_CurMachine));
//	}
//
//	Machine::SetGoal(goal);
//
//	long answer = 0;
//	while (0 != Machine::Goal)
//	{
//		for (Machine* _CurMachines : Machines)
//		{
//			_CurMachines->Work();
//		}
//		++answer;
//	}
//
//	return answer;
//}
// 

// Complete the minTime function below.
#include <algorithm>
long minTime(vector<long> machines, long goal)
{
    std::sort(machines.begin(), machines.end());

    long MinDay = machines[0];
    long MaxDay = goal * *machines.rbegin();

    long MidDay = 0;
    long SumWork = 0;
    // Binary Search
    while (MinDay < MaxDay)
    {
        MidDay = (MinDay + MaxDay) / 2;

        SumWork = 0;
        for (const long _CurMachine : machines)
        {
            SumWork += MidDay / _CurMachine;
        }

        if (SumWork >= goal)
        {
            MaxDay = MidDay;
        }
        else
        {
            MinDay = MidDay + 1;
        }
    }

    return MinDay;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nGoal_temp;
    getline(cin, nGoal_temp);

    vector<string> nGoal = split_string(nGoal_temp);

    int n = stoi(nGoal[0]);

    long goal = stol(nGoal[1]);

    string machines_temp_temp;
    getline(cin, machines_temp_temp);

    vector<string> machines_temp = split_string(machines_temp_temp);

    vector<long> machines(n);

    for (int i = 0; i < n; i++) {
        long machines_item = stol(machines_temp[i]);

        machines[i] = machines_item;
    }

    long ans = minTime(machines, goal);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
        return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}