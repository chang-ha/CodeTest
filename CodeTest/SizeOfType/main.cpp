class EmptyClass
{
public:
	void foo()
	{

	}

private:
};

class Class
{
public:

private:
	int Value = 0;
};

class VirtualClass
{
public:
	virtual void foo() = 0;

private:
};

#include <iostream>
#include <vector>
int main()
{
	// 4
	std::cout << "intSize : " << sizeof(int) << std::endl;
	size_t intSize = sizeof(int);
	// 4
	size_t floatSize = sizeof(float);
	// 1
	size_t boolSize = sizeof(bool);
	// 8
	size_t doubleSize = sizeof(double);
	// 8
	size_t longlongSize = sizeof(long long);
	// 64bit = 8, 32bit(x86) = 4
	size_t VirtualClassSize = sizeof(VirtualClass);
	// 1
	size_t EmptyClassSize = sizeof(EmptyClass);
	// 4
	size_t ClassSize = sizeof(Class);
	// 64bit = 48, 32bit = 24
	// <>* data
	// size_t size
	// size_t capacity
	size_t VectorSize = sizeof(std::vector<bool>);
	// 64bit = 8, 32bit = 4
	size_t sizetSize = sizeof(size_t);
	int a = 0;
}