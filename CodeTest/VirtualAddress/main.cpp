#include <vector>

int main()
{
	std::vector<long long*> Address_Vector;
	Address_Vector.reserve(1000);
	int LocalA = 1;
	unsigned long long Address_A = reinterpret_cast<unsigned long long>(&LocalA);

	size_t i = 0;
	while (true)
	{
		long long* B = new long long;
		*B = 1;

		if (nullptr == B)
		{
			int a = 0;
		}

		Address_Vector.push_back(B);
		size_t CurSize = Address_Vector.size();
		unsigned long long CurAddress = reinterpret_cast<unsigned long long>(Address_Vector[CurSize - 1]);
		if (Address_A >= CurAddress)
		{
			int a = 0;
		}
		++i;
	}
}