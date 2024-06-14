#include <iostream>

using namespace std;

int main(void) 
{
    int n;
    cin >> n;
	switch (n % 2)
	{
	case 0:
		std::cout << n << " is even" << std::endl;
		break;
	case 1:
		std::cout << n << " is odd" << std::endl;
		break;
	default:
		std::cout << "fail" << std::endl;
		break;
	}
    return 0;
}