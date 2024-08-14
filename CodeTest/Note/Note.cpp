#include <TimeCheck\TimeCheck.h>

struct AlignedData {
    char b;      // 1 byte
    // Padding: 3 bytes
    int a;       // 4 bytes (aligned to 4-byte boundary)
    double c;    // 8 bytes (aligned to 8-byte boundary)
    // Total size: 16 bytes
};

struct UnalignedData {
    char b;      // 1 byte
    double c;    // 8 bytes
    int a;       // 4 bytes
    // Total size: 20 bytes (may be padded to 24 bytes by compiler)
};


int main()
{
    size_t a = sizeof(AlignedData);
    size_t b = sizeof(UnalignedData);
    TIME_UNIT ATime = CheckFunctionTime([&]()
        {
        });

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
        });

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
		});

	int x = 0;
}