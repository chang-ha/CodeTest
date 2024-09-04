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
int main()
{
	std::vector<MyClass> Vector;
	MyClass A(2);
	MyClass B(4);
	auto Add = std::addressof(A);

	Vector.reserve(6);
	// reserve안해주면 vector의 capacity를 넘어서면 
	// 모든 MyClass 객체가 이동생성자 호출 및 소멸자 호출됨
	// 새로운 vector로 원소들은 이동 / 기존 vector 객체들은 소멸
	// 여기서 vector의 reserve 중요성이 또 강조됨


	std::cout << "1. Parameter : push_back vs emplace_back" << std::endl;
	std::cout << "(1) push_back 호출" << std::endl;
	// 1. Vector에 삽입을 위한 임시객체 생성
	// 2. 해당 객체 이동 연산
	// 3. 임시객체 소멸
	Vector.push_back(1);
	std::cout << "(2) emplace_back 호출" << std::endl;
	// 1. Vector 내부에서 생성자 호출
	Vector.emplace_back(3);
	std::cout << std::endl;

	// 차이 없음
	std::cout << "2. Default Constructer : push_back vs emplace_back" << std::endl;
	std::cout << "(1) push_back(객체) 호출" << std::endl;
	// 1. 임시 객체 생성
	// 2. 이동 연산
	// 3. 임시 객체 소멸
	Vector.push_back(MyClass(2));
	std::cout << "(2) emplace_back(객체) 호출" << std::endl;
	// 1. 임시 객체 생성
	// 2. 이동 연산
	// 3. 임시 객체 소멸
	Vector.emplace_back(MyClass(2));
	std::cout << std::endl;

	// 차이 없음
	std::cout << "3. Move Constructor : push_back vs emplace_back" << std::endl;
	std::cout << "(1) push_back(move) 호출" << std::endl;
	// 1. 이동 연산
	Vector.push_back(std::move(A));
	std::cout << "(2) emplace_back(move) 호출" << std::endl;
	// 1. 이동 연산
	Vector.emplace_back(std::move(B));
	std::cout << "-----------------" << std::endl;

	// 추가사항
	// vector의 erase
	// vector의 자료 구조 특성상 중간 멤버를 지우면
	// 뒤에 존재하는 모든 멤버들을 한 칸씩 땡겨야함
	std::cout << "*. vector erase" << std::endl;
	Vector.erase(Vector.begin());

	std::vector<std::vector<int>> DoubleVector;
	// DoubleVector.push_back(10);
	std::cout << "4. emplace_back 사용 시 주의 사항" << std::endl;
	// 이차원 벡터에서 push_back은 컴파일 타임에 에러를 찾을 수 있지만
	// DoubleVector.push_back(10);
	// emplace_back은 의도하지 않는 상황이 발생할 수 있음 
	//	-> 모든 유형의 생성자를 호출하기 때문
	//	-> vector(10) 생성자 호출된 꼴 << size = 10, variable = 0;
	DoubleVector.emplace_back(10, 0);

	int x = 0;
}