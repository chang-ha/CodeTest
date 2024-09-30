#include <string>

class Person
{
public:
	Person(int _Age, const std::string& _Name)
		// ���߿� �ʱ�ȭ
		: Age(_Age), Name(_Name)
	{

	}

	~Person()
	{
		
	}

	// ���� �ʱ�ȭ
	int Age = -1;
	std::string Name = "Default Person";
private:

};

class Asian : public Person
{
public:
	Asian()
		: Person(30, "Asian")
	{
	}
private:

};

class American : public Person
{
public:
	American()
		: Person(40, "American")
	{

	}
private:

};

#include <iostream>
int main()
{
	Person* APerson = new Person(10, "Person");
	Asian* AAsian = new Asian();
	Person* BAsian = new Asian();
	American* AAmerican = new American();
	Person* BAmerican = new American();

	// virtual ���� ��ĳ������ ����
	dynamic_cast<Person*>(AAsian);
	dynamic_cast<Person*>(AAmerican);

	// virtual ���� �ٿ�ĳ������ �Ұ���
	// dynamic_cast<Asian*>(BAsian);
	// dynamic_cast<Asian*>(BAmerican);
}