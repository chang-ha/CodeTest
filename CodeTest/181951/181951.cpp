#include <iostream>

using namespace std;

class MyClass
{
public:
    MyClass()
        : A(0), B(0)
    {

    }

    MyClass(int _X, int _Y)
        : A(_X), B(_Y)
    {

    }

    ~MyClass() = default;

    friend std::istream& operator>>(std::istream& _Input, MyClass& _MyClass)
    {
        _Input >> _MyClass.A >> _MyClass.B;
        return _Input;
    }

    friend std::ostream& operator<<(std::ostream& _Output, const MyClass& _MyClass)
    {
        _Output << "a = " << _MyClass.A << std::endl << "b = " << _MyClass.B << std::endl;
        return _Output;
    }

private:
    int A = 0;
    int B = 0;
};

int main(void) 
{
    // int a;
    // int b;
    // cin >> a >> b;
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;

    MyClass InputValue;
    std::cin >> InputValue;
    std::cout << InputValue;

    return 0;
}