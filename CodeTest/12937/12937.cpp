#include <string>
#include <vector>

using namespace std;

string solution(int num) 
{
	return 0 == num % 2 ? "Even" : "Odd";
	// bit 연산이 조금 더 느리게 나옴 (큰 차이 X)
	// return num & 1 ? "Odd" : "Even";
}