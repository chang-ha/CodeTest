#include <string>

class Person
{
public:
	Person(int _Age, const std::string& _Name)
		// 나중에 초기화
		: Age(_Age), Name(_Name)
	{

	}

	~Person()
	{
		
	}

	// 먼저 초기화
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

	// virtual 없이 업캐스팅은 가능
	dynamic_cast<Person*>(AAsian);
	dynamic_cast<Person*>(AAmerican);

	// virtual 없이 다운캐스팅은 불가능
	// dynamic_cast<Asian*>(BAsian);
	// dynamic_cast<Asian*>(BAmerican);
}