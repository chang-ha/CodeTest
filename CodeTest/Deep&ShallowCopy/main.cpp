class MyClass
{
public:
	MyClass()
	{
		CA = new char();
		SA = new short();
		A = new int();
		LA = new long long();
		DA = new double();
		*A = 100;
		*LA = 500;

	};
	~MyClass()
	{
		delete CA; // 5����Ʈ ����
		delete SA; // 6����Ʈ ����
		delete A; // 8����Ʈ ����
		delete LA; // 12����Ʈ ����
		delete DA; // 12����Ʈ ����
		// ������ ���� �޸𸮸� �Ҵ��ϸ� 4����Ʈ�� ������尡 ������
		// �ش� �������� ũ�� ������ �����ϰ� ���� (delete�� �󸶳� �޸𸮸� �����ؾ� �ϳ�?)
		// �����Ϸ��� �ý��۸��� �ٸ������� ���� 4����Ʈ or 8����Ʈ ����Ѵ�

		// delete�� Nullüũ ��������
		// Null�̸� ������ �ƹ��͵� ����
	};

	char* CA; // 1
	short* SA; // 2
	int* A; // 4
	long* NullA;
	int* MallocA;
	long long* LA; // 8
	double* DA;
};

int main()
{
	MyClass FirstClass;
	MyClass SecondClass = FirstClass;
	int x = 0;
}