#include <string>
#include <vector>

using namespace std;

string solution(int num) 
{
	return 0 == num % 2 ? "Even" : "Odd";
	// bit ������ ���� �� ������ ���� (ū ���� X)
	// return num & 1 ? "Odd" : "Even";
}