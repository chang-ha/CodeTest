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
	// 2600��
	++LoopCount1;
	long long A = 1; // 8����Ʈ �Ҵ� + 24����Ʈ �е�
	long long B = 1; // 8����Ʈ �Ҵ� + 24����Ʈ �е�
	long long C = 1; // 8����Ʈ �Ҵ� + 24����Ʈ �е�
	long long D = 1; // 8����Ʈ �Ҵ� + 24����Ʈ �е�
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
	// 3200��
	++LoopCount2;
	MyStruct_32Byte mMystruct; // 32byte �Ҵ� + 32byte �е� (3200��)
	// MyStruct_28Byte mMystruct2;// 28byte �Ҵ� + 36byte �е�
	// MyStruct_24Byte mMystruct3;// 24byte �Ҵ� + 24byte �е�
	// MyStruct_16Byte mMystruct4;// 16byte �Ҵ� + 32byte �е�
	// MyStruct_1Byte mMystruct5;// 1byte �Ҵ� + 35byte �е� (3500��)
	// MyStruct_48Byte mMystruct6;// 48byte �Ҵ� + 32byte �е� (3500��)
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

	// �����ϰ� 32byte ������ ���������
	// 8����Ʈ ���� ���� ���� -> ���������� 128����Ʈ ���� �޸� ���
	// 32����Ʈ ����ü ���� -> ���������� 64����Ʈ ���� �޸� ���
	std::thread StackFrame1(LocalMember);
	std::thread StackFrame2(LocalStruct);
	StackFrame1.join();
	StackFrame2.join();
}