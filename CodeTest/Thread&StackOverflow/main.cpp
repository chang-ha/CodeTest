#include <thread>
#include <iostream>
#include <string>
static int LoopCount1 = 0;
static int LoopCount2 = 0;
static int LoopCount3 = 0;
static int LoopCount4 = 0;
static int LoopCount5 = 0;
void Recursive1()
{
	++LoopCount1;
	Recursive1();
}

void Recursive2()
{
	++LoopCount2;
	Recursive2();
}
void Recursive3()
{
	++LoopCount3;
	Recursive3();
}
void Recursive4()
{
	++LoopCount4;
	Recursive4();
}
void Recursive5()
{
	++LoopCount5;
	Recursive5();
}
void InfinityLoop()
{
	Recursive1();
}


int main()
{
	std::thread A1(Recursive1);
	std::thread A2(Recursive2);
	std::thread A3(Recursive3);
	std::thread A4(Recursive4);
	Recursive5();
	A1.join();
	A2.join();
	A3.join();
	A4.join();
}