#include "MyVector.h"

#include <iostream>
class MyClass
{
public:
	MyClass();
	MyClass(int A);
	~MyClass();

	// MyClass(const MyClass& _Others) = delete;
	// MyClass& operator=(const MyClass& _Other) = delete;
	// MyClass(MyClass&& _Others) = delete;
	// MyClass& operator=(MyClass&& _Other) = delete;
	MyClass(const MyClass& _Others) noexcept;
	MyClass& operator=(const MyClass& _Other)
	{
		std::cout << "MyClass 복사 대입 연산자" << std::endl;
		return *this;
	}
	MyClass(MyClass&& _Others) noexcept;
	MyClass& operator=(MyClass&& _Other) noexcept
	{
		std::cout << "MyClass 이동 대입 연산자" << std::endl;
		return *this;
	}

private:
	// 초기화 먼저 적용됨
	int MemberVar;
};

MyClass::MyClass()
// 초기화 나중에 적용됨
	: MemberVar(0)
{
	std::cout << "MyClass 생성자1 호출" << std::endl;
}

MyClass::MyClass(int A)
// 초기화 나중에 적용됨
	: MemberVar(A)
{
	std::cout << "MyClass 생성자2 호출" << std::endl;
}

MyClass::~MyClass()
{
	std::cout << "MyClass 소멸자 호출" << std::endl;
}

MyClass::MyClass(const MyClass& _Others) noexcept
{
	this->MemberVar = _Others.MemberVar;
	std::cout << "MyClass 복사 생성자 호출" << std::endl;
}

MyClass::MyClass(MyClass&& _Others) noexcept
{
	this->MemberVar = _Others.MemberVar;
	_Others.MemberVar = 0;
	std::cout << "MyClass 이동 생성자 호출" << std::endl;
}


#include <vector>
void Function(std::vector<MyClass> _Vector)
{
	int a = 0;
}

void RefFunction(std::vector<MyClass>& _Vector)
{
	int a = 0;
}

int main()
{
	MyVector<int> A;
	for (size_t i = 0; i < 10; i++)
	{
		A.push_back(i);
	}

	MyVector<MyClass> MYVector(10);
	std::vector<MyClass> Vector(10);
	MyVector<MyClass> moveMYVector(10);
	std::vector<MyClass> moveVector(10);
	MyVector<MyClass> copyMYVector(10);
	std::vector<MyClass> copyVector(10);
	for (size_t i = 0; i < 10; i++)
	{
		moveVector[i] = std::move(Vector[i]);
		moveMYVector[i] = std::move(Vector[i]);
	}
	for (size_t i = 0; i < 10; i++)
	{
		copyVector[i] = Vector[i];
		copyMYVector[i] = Vector[i];
	}
	copyVector.reserve(20);
	copyMYVector.reserve(20);
	int a = 0;
}