class MyClass
{
public:
	MyClass()
	{
		CA = new char();
		SA = new short();
		A = new int(100);
		LA = new long long(500);
		DA = new double();
		// NullA = nullptr;
	};

	MyClass(const MyClass& _Other)
	{
		// ���� ����
		// �ܼ��� ��������� ������ �״�� ���� (��������� ����)
		// double free���ɼ�
		// CA = _Other.CA;
		// SA = _Other.SA;
		// A = _Other.A;
		// LA = _Other.LA;
		// DA = _Other.DA;

		// ���� ����
		// ���� �޸𸮸� �Ҵ��ؼ� ������ ���� (��������� ����)
		CA = new char(*_Other.CA);
		SA = new short(*_Other.SA);
		A = new int(*_Other.A);
		LA = new long long(*_Other.LA);
		DA = new double(*_Other.DA);
	}

	// MyClass(MyClass&& _Other) = default; << default�� ���� ����
	// �Ͻ��� ���� = ���� ����

	// MyClass(MyClass&& _Other)
	// {
	// 	// �̵�������
	// 	CA = _Other.CA;
	// 	SA = _Other.SA;
	// 	A = _Other.A;
	// 	LA = _Other.LA;
	// 	DA = _Other.DA;
	   
	// 	_Other.CA = nullptr;
	// 	_Other.SA = nullptr;
	// 	_Other.A = nullptr;
	// 	_Other.LA = nullptr;
	// 	_Other.DA = nullptr;
	// }

	~MyClass()
	{
		delete CA; // 5����Ʈ ����
		delete SA; // 6����Ʈ ����
		delete A; // 8����Ʈ ����
		delete LA; // 12����Ʈ ����
		delete DA; // 12����Ʈ ����
		// ������ ���� �޸𸮸� �Ҵ��ϸ� 4����Ʈ�� ������尡 ������ (malloc�� ����)
		// �ش� �������� ũ�� ������ �����ϰ� ���� (delete�� �󸶳� �޸𸮸� �����ؾ� �ϳ�?)
		// �����Ϸ��� �ý��۸��� �ٸ������� ���� 4����Ʈ or 8����Ʈ ����Ѵ�

		// delete�� Nullüũ ��������
		// Null�̸� ������ �ƹ��͵� ����
		delete NullA;

		// ��� �̷��� ���� delete�ϴ°� ����
		// RAII��Ģ�� ����� std::shared_ptr���� ����ϴ� ���� ����
	};

	char* CA; // 1
	short* SA; // 2
	int* A; // 4
	long* NullA; // 8
	long long* LA; // 8
	double* DA; // 8
	// total 48
};

#include <stdlib.h>
#include <utility>
int main()
{
	MyClass* newClass = new MyClass();
	size_t ClassSize = sizeof(MyClass);
	delete newClass;

	// class���� ����
	// 48����Ʈ¥�� Ŭ����������
	// ���� ������ 52����Ʈ �Ҵ� �� ����

	MyClass FirstClass;
	MyClass SecondClass = FirstClass;
	MyClass ThridClass = std::move(SecondClass);
	*FirstClass.A = 1;
	*ThridClass.A = 3;
	*SecondClass.A = 2;
	int x = 0;
}