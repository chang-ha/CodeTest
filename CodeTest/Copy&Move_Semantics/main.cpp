#include <iostream>

class MyClass
{
public:
	MyClass()
	{
		std::cout << "Class Default Constructor" << std::endl;
	}

	~MyClass()
	{
		std::cout << "Class Destructor" << std::endl;
	}

	MyClass(const MyClass& _Ohter)
	{
		std::cout << "Class Copy Constructor" << std::endl;
	}

	MyClass& operator=(const MyClass& _Other)
	{
		std::cout << "Class Copy Assignment" << std::endl;
	}

	MyClass(MyClass&& _Ohter) noexcept
	{
		std::cout << "Class Move Constructor" << std::endl;
	}

	MyClass& operator=(MyClass&& _Other) noexcept
	{
		std::cout << "Class Move Assignment" << std::endl;
	}

};

int main()
{
	MyClass FirstMyClass;

	std::cout << &FirstMyClass << std::endl;

	MyClass SecondMyClass = FirstMyClass;

	std::cout << &SecondMyClass << std::endl;

	MyClass ThridMyClass = std::move(FirstMyClass);
	std::cout << &FirstMyClass << std::endl;
	std::cout << &ThridMyClass << std::endl;

	int a = 0;
	int&& RRef = 10;
	const int& CRef = 10;
	// int& Ref = 10;
	// int&& RRefa = a;
	RRef = a;

	int b = 0;
}