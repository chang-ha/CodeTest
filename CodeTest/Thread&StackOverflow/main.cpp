#include <thread>
#include <iostream>
#include <string>
static int LoopCount1 = 0;
static int LoopCount2 = 0;
static int LoopCount3 = 0;
static int LoopCount4 = 0;
static int LoopCount5 = 0;

void Recursive1()
{
	++LoopCount1;
	Recursive1();
}

void Recursive2()
{
	++LoopCount2;
	Recursive2();
}
void Recursive3()
{
	++LoopCount3;
	Recursive3();
}
void Recursive4()
{
	++LoopCount4;
	Recursive4();
}

void Recursive5()
{
	++LoopCount5;
	Recursive5();
}

void LocalMember()
{
	// 2600대
	++LoopCount1;
	long long A = 1; // 8바이트 할당 + 24바이트 패딩
	long long B = 1; // 8바이트 할당 + 24바이트 패딩
	long long C = 1; // 8바이트 할당 + 24바이트 패딩
	long long D = 1; // 8바이트 할당 + 24바이트 패딩
	// long long A_ptr = reinterpret_cast<long long>(&A);
	// long long B_ptr = reinterpret_cast<long long>(&B);
	// long long C_ptr = reinterpret_cast<long long>(&C);
	// long long D_ptr = reinterpret_cast<long long>(&D);

	LocalMember();
}

struct MyStruct_32Byte
{
	long long A = 1;
	long long B = 2;
	long long C = 3;
	long long D = 4;
};

struct MyStruct_28Byte
{
	long long A = 1;
	long long B = 2;
	long long C = 3;
	int D = 4;
};

struct MyStruct_24Byte
{
	long long A = 1;
	long long B = 2;
	long long C = 3;
};

struct MyStruct_16Byte
{
	long long A = 1;
	long long B = 2;
};

struct MyStruct_1Byte
{
	char A = '1';
};

struct MyStruct_48Byte
{
	long long A = 1;
	long long B = 2;
	long long C = 3;
	long long D = 4;
	long long E = 5;
	long long F = 6;
};


void LocalStruct()
{
	// 3200대
	++LoopCount2;
	MyStruct_32Byte mMystruct; // 32byte 할당 + 32byte 패딩 (3200대)
	// MyStruct_28Byte mMystruct2;// 28byte 할당 + 36byte 패딩
	// MyStruct_24Byte mMystruct3;// 24byte 할당 + 24byte 패딩
	// MyStruct_16Byte mMystruct4;// 16byte 할당 + 32byte 패딩
	// MyStruct_1Byte mMystruct5;// 1byte 할당 + 35byte 패딩 (3500대)
	// MyStruct_48Byte mMystruct6;// 48byte 할당 + 32byte 패딩 (3500대)
	// long long Struct_ptr = reinterpret_cast<long long>(&mMystruct);
	// long long Struct_ptr2 = reinterpret_cast<long long>(&mMystruct2);
	// long long Struct_ptr3 = reinterpret_cast<long long>(&mMystruct3);
	// long long Struct_ptr4 = reinterpret_cast<long long>(&mMystruct4);
	// long long Struct_ptr5 = reinterpret_cast<long long>(&mMystruct5);
	// long long Struct_ptr6 = reinterpret_cast<long long>(&mMystruct6);
	LocalStruct();
}

int main()
{
	// std::thread A1(Recursive1);
	// std::thread A2(Recursive2);
	// std::thread A3(Recursive3);
	// std::thread A4(Recursive4);
	// Recursive5();
	// A1.join();
	// A2.join();
	// A3.join();
	// A4.join();

	// 동일하게 32byte 변수를 사용했지만
	// 8바이트 지역 변수 사용시 -> 지역변수가 128바이트 스택 메모리 사용
	// 32바이트 구조체 사용시 -> 지역변수가 64바이트 스택 메모리 사용
	std::thread StackFrame1(LocalMember);
	std::thread StackFrame2(LocalStruct);
	StackFrame1.join();
	StackFrame2.join();
}