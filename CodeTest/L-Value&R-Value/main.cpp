int& RefFunction(int& _A)
{
	return _A;
}

int Function(int _A)
{
	return _A;
}

int main()
{
	// L-Value
	//	- 주소값을 취할 수 있는 값
	//	- L-Value는 표현식의 왼쪽, 오른쪽 모두 올 수 있음
	int a = 0;
	int* a_address = &a;

	// R-Value 
	//	- 주소값을 취할 수 없는 값
	//	- R-Value는 표현식의 오른쪽에만 올 수 있음
	a = 10;

	// Reference 
	// 1. lvalue Reference
	// 흔히 다루는 레퍼런스는 L-Value에만 레퍼런스를 가질 수 있음
	int& a_Reference = a;
	// lvalue Reference 자체도 L-Value가 될 수 있음
	int& a_Ref_Ref = a_Reference;
	// R-Value는 레퍼런스를 가질 수 없음
	// int& int_Reference = 10;

	// 함수의 리턴이 Ref타입이면 좌측값에 올 수 있음
	RefFunction(a) = 20;

	// 하지만 Ref타입이 아니면 좌측값에 올 수 없음
	//	Function(a) = 5;
	// 주소값을 취하는 것도 불가능
	//  &Function(a);
	// 우측값에 오는 경우는 가능
	a = Function(a);

	// 2. rvalue Reference
	int&& RRef = 10;
	const int& CRef = 10;
	// int&& RRefa = a;
	RRef = a;
}