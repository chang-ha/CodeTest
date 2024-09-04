using namespace std;

#include <iostream>
class MyClass
{
public:
	MyClass();
	MyClass(int A);
	~MyClass();

	MyClass(const MyClass& _Others) noexcept;
	MyClass& operator=(const MyClass& _Other)
	{
		std::cout << "MyClass ���� ���� ������" << std::endl;
		return *this;
	}
	MyClass(MyClass&& _Others) noexcept;
	MyClass& operator=(MyClass&& _Other) noexcept
	{
		std::cout << "MyClass �̵� ���� ������" << std::endl;
		return *this;
	}

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

MyClass::MyClass(const MyClass& _Others) noexcept
{
	this->MemberVar = _Others.MemberVar;
	std::cout << "MyClass ���� ������ ȣ��" << std::endl;
}

MyClass::MyClass(MyClass&& _Others) noexcept
{
	this->MemberVar = _Others.MemberVar;
	_Others.MemberVar = 0;
	std::cout << "MyClass �̵� ������ ȣ��" << std::endl;
}


#include <vector>
int main()
{
	std::vector<MyClass> Vector;
	MyClass A(2);
	MyClass B(4);
	auto Add = std::addressof(A);

	Vector.reserve(6);
	// reserve�����ָ� vector�� capacity�� �Ѿ�� 
	// ��� MyClass ��ü�� �̵������� ȣ�� �� �Ҹ��� ȣ���
	// ���ο� vector�� ���ҵ��� �̵� / ���� vector ��ü���� �Ҹ�
	// ���⼭ vector�� reserve �߿伺�� �� ������


	std::cout << "1. Parameter : push_back vs emplace_back" << std::endl;
	std::cout << "(1) push_back ȣ��" << std::endl;
	// 1. Vector�� ������ ���� �ӽð�ü ����
	// 2. �ش� ��ü �̵� ����
	// 3. �ӽð�ü �Ҹ�
	Vector.push_back(1);
	std::cout << "(2) emplace_back ȣ��" << std::endl;
	// 1. Vector ���ο��� ������ ȣ��
	Vector.emplace_back(3);
	std::cout << std::endl;

	// ���� ����
	std::cout << "2. Default Constructer : push_back vs emplace_back" << std::endl;
	std::cout << "(1) push_back(��ü) ȣ��" << std::endl;
	// 1. �ӽ� ��ü ����
	// 2. �̵� ����
	// 3. �ӽ� ��ü �Ҹ�
	Vector.push_back(MyClass(2));
	std::cout << "(2) emplace_back(��ü) ȣ��" << std::endl;
	// 1. �ӽ� ��ü ����
	// 2. �̵� ����
	// 3. �ӽ� ��ü �Ҹ�
	Vector.emplace_back(MyClass(2));
	std::cout << std::endl;

	// ���� ����
	std::cout << "3. Move Constructor : push_back vs emplace_back" << std::endl;
	std::cout << "(1) push_back(move) ȣ��" << std::endl;
	// 1. �̵� ����
	Vector.push_back(std::move(A));
	std::cout << "(2) emplace_back(move) ȣ��" << std::endl;
	// 1. �̵� ����
	Vector.emplace_back(std::move(B));
	std::cout << "-----------------" << std::endl;

	// �߰�����
	// vector�� erase
	// vector�� �ڷ� ���� Ư���� �߰� ����� �����
	// �ڿ� �����ϴ� ��� ������� �� ĭ�� ���ܾ���
	std::cout << "*. vector erase" << std::endl;
	Vector.erase(Vector.begin());

	std::vector<std::vector<int>> DoubleVector;
	// DoubleVector.push_back(10);
	std::cout << "4. emplace_back ��� �� ���� ����" << std::endl;
	// ������ ���Ϳ��� push_back�� ������ Ÿ�ӿ� ������ ã�� �� ������
	// DoubleVector.push_back(10);
	// emplace_back�� �ǵ����� �ʴ� ��Ȳ�� �߻��� �� ���� 
	//	-> ��� ������ �����ڸ� ȣ���ϱ� ����
	//	-> vector(10) ������ ȣ��� �� << size = 10, variable = 0;
	DoubleVector.emplace_back(10, 0);

	int x = 0;
}