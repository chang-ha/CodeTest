#include <string>
#include <vector>

using namespace std;

// for-loop or while-loop
// 시간복잡도 O(n)
int solution(int n)
{
	long long First = 0;
	long long Second = 1;
	long long Third = 1;

	for (int i = 2; i <= n; i++)
	{
		Third = (First + Second) % 1234567;
		First = Second % 1234567;
		Second = Third % 1234567;
	}

	return static_cast<int>(Third);
}

// 재귀함수 개선을 위한 메모이제이션
// 시간복잡도 O(n)
// 공간복잡도가 높음
#include <array>
int MemoizationFibonacci(const int n)
{
	static std::vector<long long> Fibonacci = { 0, 1, 1, };
	Fibonacci.reserve(n);

	if (2 >= n)
	{
		return 1;
	}

	if (0 == Fibonacci[n])
	{
		Fibonacci[n] = MemoizationFibonacci(n - 1) + MemoizationFibonacci(n - 2);
	}

	return Fibonacci[n] % 1234567;
}

int Memoizationsolution(int n)
{
	int answer = MemoizationFibonacci(n);
	return answer;
}

// 재귀함수 효율성 낮음
// 시간복잡도 O(2^n)
int RecursiveFibonacci(const int n)
{
	if (0 > n)
	{
		// Error
		return 0;
	}

	if (1 == n)
	{
		return 1;
	}

	if (0 == n)
	{
		return 0;
	}

	int answer = RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
	return answer;
}

int Recursivesolution(int n)
{
	int answer = RecursiveFibonacci(n);
	return answer % 1234567;
}