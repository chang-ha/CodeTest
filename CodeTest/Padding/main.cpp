#include <TimeCheck\TimeCheck.h>
#include <iostream>
#include <intrin.h>
#include <vector>

unsigned int cacheLineSize = 0;
unsigned int PaddingSize = 0;
#define PADDING 100

struct UnalignedData {

	UnalignedData()
	{
		data.resize(cacheLineSize - PaddingSize);
	}

	std::vector<char> data;
};

struct PaddedData {
	PaddedData()
	{
		data.resize(cacheLineSize - PaddingSize);
		padding.resize(PaddingSize);
	}

	std::vector<char> data;
	std::vector<char> padding;
};

class BytePaddingConsider
{
public:
	BytePaddingConsider() = default;
	~BytePaddingConsider() = default;

	char C = '1'; // 1����Ʈ (+ 1����Ʈ �е�)
	short E = 1; // 2����Ʈ
	int A = 1; // 4����Ʈ
	// BytePadding���� ���� 8����Ʈ ����

	long long B = 1; // 8����Ʈ
	double D = 1.0; // 8����Ʈ
	long long F = 1;// 8����Ʈ
	// �� 32����Ʈ ����
};

class BytePaddingNotConsider
{
public:
	BytePaddingNotConsider() = default;
	~BytePaddingNotConsider() = default;

	int A = 1; // 8����Ʈ ���� (4����Ʈ �е�)
	long long B = 1; // 8����Ʈ ����
	char C = '1'; // 8����Ʈ ���� (7����Ʈ �е�)
	double D = 1.0; // 8����Ʈ ����
	short E = 1; // 8����Ʈ ���� (6����Ʈ �е�)
	long long F = 1; // 8����Ʈ ����
	// �� 48����Ʈ
};

#pragma pack(push, 1)
class NotBytePadding
{
public:
	NotBytePadding() = default;
	~NotBytePadding() = default;

	int A = 1; // 4����Ʈ ����
	long long B = 1; // 8����Ʈ ����
	char C = '1'; // 1����Ʈ ����
	double D = 1.0; // 8����Ʈ ����
	short E = 1; // 2����Ʈ ����
	long long F = 1; // 8����Ʈ ����
	// �� 31����Ʈ
};
#pragma pack(pop)

//class alignas(8) AdjustBytePadding
//{
//	char a;  // 8����Ʈ ���� ����
//	char c;
//	int b;
//	// 8����Ʈ
//};

class AdjustBytePadding
{
	alignas(8) char a;  // 8����Ʈ ���� ����
	char c;
	int b;
	// 8����Ʈ
};

class NotAdjustBytePadding
{
	char a;  // Byte�� ���� ū �ڷ����� int(4����Ʈ) �������� �ڵ� ����
	int b;
	char c;
	// 12����Ʈ
};

class CantAdjustBytePadding
{
	alignas(4) char a;  // 4����Ʈ ���� ���� �õ�
	char c;
	long long b; // 8����Ʈ �ڷ����� ����
	// ���� ������(ũ�Ⱑ ū) ����Ʈ�� �е�
	// 16����Ʈ
};

int main()
{
	int cpuInfo[4] = { -1 };
	__cpuid(cpuInfo, 4); // CPUID ��ɾ� ȣ��
	cacheLineSize = (cpuInfo[1] & 0x0FFF0000) >> 16; // ĳ�� ���� ũ�� ����
	std::cout << "Cache Line Size: " << cacheLineSize << " bytes" << std::endl; // 704 ����Ʈ
	PaddingSize = cacheLineSize - PADDING;

	unsigned int LoopCount = cacheLineSize - PaddingSize;
	std::vector<int> A;
	// ���ο� 1. ������, 2. size_t �迭 size, 3. size_t �迭 capacity
	// 32bit -> 16byte (12byte���� bytepadding���� ���� 16byte)
	// 64bit -> 32byte (24byte���� bytepadding���� ���� 32byte)
 	size_t A_Size = sizeof(A);

	// BytePadding �޸� Ȯ��
	BytePaddingConsider* BPC = new BytePaddingConsider();
	BytePaddingNotConsider* BPNC = new BytePaddingNotConsider();
	NotBytePadding* NBP = new NotBytePadding();
	delete BPNC;
	delete BPC;
	delete NBP;
	size_t ConsiderBytePadding = sizeof(BytePaddingConsider);
	size_t NotConsiderBytePadding = sizeof(BytePaddingNotConsider);
	size_t NotBytePaddingSize = sizeof(NotBytePadding);

	size_t Adjust = sizeof(AdjustBytePadding);
	size_t NotAdjust = sizeof(NotAdjustBytePadding);
	size_t CantAdjust = sizeof(CantAdjustBytePadding);

	UnalignedData Unalignedarray[10] = {};
	PaddedData Paddedarray[10] = {};

	constexpr size_t BytePaddingLoopCount = 10000;

	NotBytePadding* mNotBytePadding = new NotBytePadding();
	BytePaddingNotConsider* mBytePaddingNotConsider = new BytePaddingNotConsider();
	BytePaddingConsider* mBytePaddingConsider = new BytePaddingConsider();

	//TIME_UNIT ATime = CheckFunctionTime([&]()
	//	{
	//		for (size_t i = 0; i < 10; i++)
	//		{
	//			for (size_t j = 0; j < LoopCount; j++)
	//			{
	//				Unalignedarray[i].data[j] = char(j);
	//			}
	//		}
	//	});

	//TIME_UNIT BTime = CheckFunctionTime([&]()
	//	{
	//		for (size_t i = 0; i < 10; i++)
	//		{
	//			for (size_t j = 0; j < LoopCount; j++)
	//			{
	//				Paddedarray[i].data[j] = char(j);
	//			}
	//		}
	//	});

	// ������ �������δ� ����Ʈ �е��� ���� ����ð� ���� ũ�� ���� �� ����
	// �޸� ���̴� Ȯ���� ����
	// �̷������δ� ����Ʈ �е��� ���� �޸� ������ CPU�� ������带 ���� �� ����
	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
			// Not consider Byte Padding
			for (size_t i = 0; i < BytePaddingLoopCount; i++)
			{
				mBytePaddingNotConsider->B = LLONG_MAX - i;
				mBytePaddingNotConsider->F = LLONG_MAX - i;
			}
		});


	TIME_UNIT ETime = CheckFunctionTime([&]()
		{
			// consider Byte Padding
			for (size_t i = 0; i < BytePaddingLoopCount; i++)
			{
				mBytePaddingConsider->B = LLONG_MAX - i;
				mBytePaddingConsider->F = LLONG_MAX - i;
			}
		});


	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
			// Not Byte Padding(#pragma pack)
			for (size_t i = 0; i < BytePaddingLoopCount; i++)
			{
				mNotBytePadding->B = LLONG_MAX - i;
				mNotBytePadding->F = LLONG_MAX - i;
			}
		});
	int x = 0;
}