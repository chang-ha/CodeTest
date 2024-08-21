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
		delete CA; // 5바이트 해제
		delete SA; // 6바이트 해제
		delete A; // 8바이트 해제
		delete LA; // 12바이트 해제
		delete DA; // 12바이트 해제
		// 실제로 힙에 메모리를 할당하면 4바이트의 오버헤드가 존재함
		// 해당 오버헤드는 크기 정보를 포함하고 있음 (delete시 얼마나 메모리를 해제해야 하나?)
		// 컴파일러나 시스템마다 다르다지만 보통 4바이트 or 8바이트 사용한다

		// delete시 Null체크 하지말자
		// Null이면 어차피 아무것도 안함
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