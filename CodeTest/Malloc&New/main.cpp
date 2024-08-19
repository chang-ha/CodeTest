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
		// 얕은 복사
		// 단순히 멤버변수의 값들을 그대로 복사 (멤버변수를 복사)
		// double free가능성
		// CA = _Other.CA;
		// SA = _Other.SA;
		// A = _Other.A;
		// LA = _Other.LA;
		// DA = _Other.DA;

		// 깊은 복사
		// 새로 메모리를 할당해서 값들을 복사 (멤버변수를 복제)
		CA = new char(*_Other.CA);
		SA = new short(*_Other.SA);
		A = new int(*_Other.A);
		LA = new long long(*_Other.LA);
		DA = new double(*_Other.DA);
	}

	// MyClass(MyClass&& _Other) = default; << default시 얕은 복사
	// 암시적 생성 = 깊은 복사

	// MyClass(MyClass&& _Other)
	// {
	// 	// 이동연산자
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
		delete CA; // 5바이트 해제
		delete SA; // 6바이트 해제
		delete A; // 8바이트 해제
		delete LA; // 12바이트 해제
		delete DA; // 12바이트 해제
		// 실제로 힙에 메모리를 할당하면 4바이트의 오버헤드가 존재함 (malloc도 동일)
		// 해당 오버헤드는 크기 정보를 포함하고 있음 (delete시 얼마나 메모리를 해제해야 하나?)
		// 컴파일러나 시스템마다 다르다지만 보통 4바이트 or 8바이트 사용한다

		// delete시 Null체크 하지말자
		// Null이면 어차피 아무것도 안함
		delete NullA;

		// 사실 이렇게 직접 delete하는것 보단
		// RAII원칙이 적용된 std::shared_ptr등을 사용하는 것이 안전
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

	// class또한 동일
	// 48바이트짜리 클레스이지만
	// 실제 힙에는 52바이트 할당 및 해제

	MyClass FirstClass;
	MyClass SecondClass = FirstClass;
	MyClass ThridClass = std::move(SecondClass);
	*FirstClass.A = 1;
	*ThridClass.A = 3;
	*SecondClass.A = 2;
	int x = 0;
}