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

int main()
{
	int cpuInfo[4] = { -1 };
	__cpuid(cpuInfo, 4); // CPUID 명령어 호출
	cacheLineSize = (cpuInfo[1] & 0x0FFF0000) >> 16; // 캐시 라인 크기 추출
	std::cout << "Cache Line Size: " << cacheLineSize << " bytes" << std::endl; // 704 바이트
	PaddingSize = cacheLineSize - PADDING;

	unsigned int LoopCount = cacheLineSize - PaddingSize;
	std::vector<int> A;
	sizeof(A);

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