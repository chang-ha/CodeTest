using namespace std;

#include <iostream>
class MyClass
{
public:
	MyClass();
	MyClass(int A);
	~MyClass();

	MyClass(const MyClass& _Others);
	MyClass(MyClass&& _Others);

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

MyClass::MyClass(const MyClass& _Others)
{
	std::cout << "MyClass 복사 생성자 호출" << std::endl;
}

MyClass::MyClass(MyClass&& _Others)
{
	std::cout << "MyClass 이동 생성자 호출" << std::endl;
}

#include <vector>
int main()
{
	std::vector<MyClass> Vector;
	MyClass A(2);
	MyClass B(4);
	auto Add = std::addressof(A);

	std::cout << "push_back 호출" << std::endl;
	Vector.push_back(1); 
	std::cout << "push_back(객체) 호출" << std::endl;
	Vector.push_back(MyClass(2));
	std::cout << "push_back(move) 호출" << std::endl;
	Vector.push_back(std::move(A)); 
	std::cout << "emplace_back 호출" << std::endl;
	Vector.emplace_back(3); 
	std::cout << "emplace_back(객체) 호출" << std::endl;
	Vector.emplace_back(MyClass(2));
	std::cout << "emplace_back(move) 호출" << std::endl;
	Vector.emplace_back(std::move(B)); 
	std::cout << "-----------------" << std::endl;
	int x = 0;
}