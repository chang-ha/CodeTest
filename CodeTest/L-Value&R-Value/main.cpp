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
	//	- �ּҰ��� ���� �� �ִ� ��
	//	- L-Value�� ǥ������ ����, ������ ��� �� �� ����
	int a = 0;
	int* a_address = &a;

	// R-Value 
	//	- �ּҰ��� ���� �� ���� ��
	//	- R-Value�� ǥ������ �����ʿ��� �� �� ����
	a = 10;

	// Reference 
	// 1. lvalue Reference
	// ���� �ٷ�� ���۷����� L-Value���� ���۷����� ���� �� ����
	int& a_Reference = a;
	// lvalue Reference ��ü�� L-Value�� �� �� ����
	int& a_Ref_Ref = a_Reference;
	// R-Value�� ���۷����� ���� �� ����
	// int& int_Reference = 10;

	// �Լ��� ������ RefŸ���̸� �������� �� �� ����
	RefFunction(a) = 20;

	// ������ RefŸ���� �ƴϸ� �������� �� �� ����
	//	Function(a) = 5;
	// �ּҰ��� ���ϴ� �͵� �Ұ���
	//  &Function(a);
	// �������� ���� ���� ����
	a = Function(a);

	// 2. rvalue Reference
	int&& RRef = 10;
	const int& CRef = 10;
	// int&& RRefa = a;
	RRef = a;
}