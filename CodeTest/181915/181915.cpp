#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list) 
{
    string answer = "";

	int MyString_Size = static_cast<int>(my_string.size());
	for (const int _CurIndex : index_list)
	{
		if (MyString_Size <= _CurIndex)
		{
			// Error
			return " ";
		}

		answer += my_string[_CurIndex];
	}

    return answer;
}