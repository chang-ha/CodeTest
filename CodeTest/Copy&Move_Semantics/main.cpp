#include <iostream>

class MyClass
{
public:
	MyClass()
	{
		std::cout << "Class Default Constructor" << std::endl;
	}

	MyClass(const int i)
		: mValue(i)
	{
		std::cout << "Class Param Constructor" << std::endl;
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

	int mValue = 0;
};

#include <vector>
int main()
{
	std::cout << "size of MyClass : " << sizeof(MyClass) << std::endl;
	MyClass FirstMyClass;
	FirstMyClass.mValue = 100;

	std::cout << "FirstMyClass(Default Constructor) Address : " << &FirstMyClass << std::endl;

	MyClass SecondMyClass = FirstMyClass;

	std::cout << "SecondMyClass(Copy Constructor) Address : " << &SecondMyClass << std::endl;

	MyClass ThridMyClass = std::move(FirstMyClass);
	std::cout << "FirstMyClass Address :" <<  &FirstMyClass << std::endl;
	std::cout <<"ThridMyClass(Move Constructor) Address : " << &ThridMyClass << std::endl;

	int a = 0;
}