#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int a;
	int b;
	std::cin >> a >> b;

	std::string RowString(a, '*');

	for (int i = 0; i < b; i++)
	{
		std::cout << RowString << std::endl;
	}

	return 0;
}