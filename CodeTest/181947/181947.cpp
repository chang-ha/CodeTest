#include <iostream>

using namespace std;

void PrintPlusOperation(const int _LeftValue, const int _RightValue)
{
    std::cout << _LeftValue << " + " << _RightValue << " = " << (_LeftValue + _RightValue) << endl;
    return;
}

int main(void) 
{
    int a;
    int b;
    std::cin >> a >> b;
    PrintPlusOperation(a,b);
    return 0;
}