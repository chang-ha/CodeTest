#include <iostream>

void Function()
{

}

void Function2();

static int sA = 100;
static int sB;
static long long TestArray1[1024 * 1024 * 100];
static long long TestArray2[1024 * 1024 * 100];
static long long TestArray3[1024 * 1024 * 100];

int main()
{
	int* nA = new int;
	int* nB = new int;

	char A = '1';
	short B = 1;
	short C = 1;
	short D = 1;
	short E = 1;
	short F = 1;

	// 함수의 주소는 선언부에 따라 다름
	std::cout << "Code Memory(main) : " << reinterpret_cast<long long>(&main) << std::endl;
	std::cout << "Code Memory(function) : " << reinterpret_cast<long long>(&Function )<< std::endl;
	std::cout << "Code Memory(function2) : " << reinterpret_cast<long long>(&Function2) << std::endl;


	std::cout << "Init Data Memory : " << reinterpret_cast<long long>(&sA) << ", Init Data Value : " << sA << std::endl;
	std::cout << "Not Init Data Memory : " << reinterpret_cast<long long>(&sB) << ", Init Data Value : " << sB << std::endl;
	std::cout << "Not Init Array Memory : " << reinterpret_cast<long long>(&TestArray1) << std::endl;

	std::cout << "Heap Memory : " << reinterpret_cast<long long>(nA) << std::endl;
	std::cout << "Heap Memory : " << reinterpret_cast<long long>(nB) << std::endl;

	// 내 컴퓨터 환경에서는 Stack의 주소값이 가장 작음
	std::cout << "Stack Memory : " << reinterpret_cast<long long>(&A) << std::endl;
	std::cout << "Stack Memory : " << reinterpret_cast<long long>(&B) << std::endl;
	std::cout << "Stack Memory : " << reinterpret_cast<long long>(&C) << std::endl;
	std::cout << "Stack Memory : " << reinterpret_cast<long long>(&D) << std::endl;
	std::cout << "Stack Memory : " << reinterpret_cast<long long>(&E) << std::endl;
	std::cout << "Stack Memory : " << reinterpret_cast<long long>(&F) << std::endl;

}

void Function2()
{

}