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
	// �ʱ�ȭ ���� �����
	int MemberVar;
};

MyClass::MyClass()
	// �ʱ�ȭ ���߿� �����
	: MemberVar(0)
{
	std::cout << "MyClass ������1 ȣ��" << std::endl;
}

MyClass::MyClass(int A)
	// �ʱ�ȭ ���߿� �����
	: MemberVar(A)
{
	std::cout << "MyClass ������2 ȣ��" << std::endl;
}

MyClass::~MyClass()
{
	std::cout << "MyClass �Ҹ��� ȣ��" << std::endl;
}

MyClass::MyClass(const MyClass& _Others)
{
	std::cout << "MyClass ���� ������ ȣ��" << std::endl;
}

MyClass::MyClass(MyClass&& _Others)
{
	std::cout << "MyClass �̵� ������ ȣ��" << std::endl;
}

#include <vector>
int main()
{
	std::vector<MyClass> Vector;
	MyClass A(2);
	MyClass B(4);
	auto Add = std::addressof(A);

	std::cout << "push_back ȣ��" << std::endl;
	Vector.push_back(1); 
	std::cout << "push_back(��ü) ȣ��" << std::endl;
	Vector.push_back(MyClass(2));
	std::cout << "push_back(move) ȣ��" << std::endl;
	Vector.push_back(std::move(A)); 
	std::cout << "emplace_back ȣ��" << std::endl;
	Vector.emplace_back(3); 
	std::cout << "emplace_back(��ü) ȣ��" << std::endl;
	Vector.emplace_back(MyClass(2));
	std::cout << "emplace_back(move) ȣ��" << std::endl;
	Vector.emplace_back(std::move(B)); 
	std::cout << "-----------------" << std::endl;
	int x = 0;
}