#include <iostream>

void Function()
{

}

static int sA = 100;
static int sB;
static long long TestArray1[1024 * 1024 * 100];
static long long TestArray2[1024 * 1024 * 100];
static long long TestArray3[1024 * 1024 * 100];

int main()
{
	int* nA = new int;
	int* nB = new int;

	short B = 1;
	short C = 1;
	short D = 1;
	short E = 1;
	short F = 1;

	std::cout << "Code Memory : " << &main << std::endl;
	std::cout << "Code Memory : " << &Function << std::endl;


	std::cout << "Init Data Memory : " << &sA << ", Init Data Value : " << sA << std::endl;
	std::cout << "Not Init Data Memory : " << &sB << ", Init Data Value : " << sB << std::endl;

	std::cout << "Heap Memory : " << nA << std::endl;
	std::cout << "Heap Memory : " << nB << std::endl;

	std::cout << "Stack Memory : " << &B << std::endl;
	std::cout << "Stack Memory : " << &C << std::endl;
	std::cout << "Stack Memory : " << &D << std::endl;
	std::cout << "Stack Memory : " << &E << std::endl;
	std::cout << "Stack Memory : " << &F << std::endl;

}