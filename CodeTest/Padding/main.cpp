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

private:
	char C = '1'; // 1바이트 (+ 1바이트 패딩)
	short E = 1; // 2바이트
	int A = 1; // 4바이트
	// BytePadding으로 인해 8바이트 차지

	long long B = 1; // 8바이트
	double D = 1.0; // 8바이트
	long long F = 1;// 8바이트
	// 총 32바이트 차지
};

class BytePaddingNotConsider
{
public:
	BytePaddingNotConsider() = default;
	~BytePaddingNotConsider() = default;

private:
	int A = 1; // 8바이트 차지 (4바이트 패딩)
	long long B = 1; // 8바이트 차지
	char C = '1'; // 8바이트 차지 (7바이트 패딩)
	double D = 1.0; // 8바이트 차지
	short E = 1; // 8바이트 차지 (6바이트 패딩)
	long long F = 1; // 8바이트 차지
	// 총 48바이트
};

//class alignas(8) AdjustBytePadding
//{
//	char a;  // 8바이트 경계로 정렬
//	char c;
//	int b;
//	// 8바이트
//};

class AdjustBytePadding
{
	alignas(8) char a;  // 8바이트 경계로 정렬
	char c;
	int b;
	// 8바이트
};

class NotAdjustBytePadding
{
	char a;  // Byte가 가장 큰 자료형인 int(4바이트) 기준으로 자동 정렬
	int b;
	char c;
	// 12바이트
};

class CantAdjustBytePadding
{
	alignas(4) char a;  // 4바이트 경계로 정렬 시도
	char c;
	long long b; // 8바이트 자료형이 존재
	// 가장 엄격한(크기가 큰) 바이트로 패딩
	// 16바이트
};

int main()
{
	int cpuInfo[4] = { -1 };
	__cpuid(cpuInfo, 4); // CPUID 명령어 호출
	cacheLineSize = (cpuInfo[1] & 0x0FFF0000) >> 16; // 캐시 라인 크기 추출
	std::cout << "Cache Line Size: " << cacheLineSize << " bytes" << std::endl; // 704 바이트
	PaddingSize = cacheLineSize - PADDING;

	unsigned int LoopCount = cacheLineSize - PaddingSize;
	std::vector<int> A;
	// 내부에 1. 포인터, 2. size_t 배열 size, 3. size_t 배열 capacity
	// 32bit -> 16byte (12byte에서 bytepadding으로 인해 16byte)
	// 64bit -> 32byte (24byte에서 bytepadding으로 인해 32byte)
 	size_t A_Size = sizeof(A);

	BytePaddingConsider* BPC = new BytePaddingConsider();
	delete BPC;
	BytePaddingNotConsider* BPNC = new BytePaddingNotConsider();
	delete BPNC;
	size_t ConsiderBytePadding = sizeof(BytePaddingConsider);
	size_t NotConsiderBytePadding = sizeof(BytePaddingNotConsider);

	size_t Adjust = sizeof(AdjustBytePadding);
	size_t NotAdjust = sizeof(NotAdjustBytePadding);
	size_t CantAdjust = sizeof(CantAdjustBytePadding);

	UnalignedData Unalignedarray[10] = {};
	PaddedData Paddedarray[10] = {};

	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
			for (size_t i = 0; i < 10; i++)
			{
				for (size_t j = 0; j < LoopCount; j++)
				{
					Unalignedarray[i].data[j] = char(j);
				}
			}
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
			for (size_t i = 0; i < 10; i++)
			{
				for (size_t j = 0; j < LoopCount; j++)
				{
					Paddedarray[i].data[j] = char(j);
				}
			}
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
		});

	int x = 0;
}