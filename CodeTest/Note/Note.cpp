#include <bits/stdc++.h>
using namespace std;


class CTest
{
public:
	int  mA;

public:
	CTest Create()
	{
		CTest mCTest;
		return mCTest;
	}
};


class CSingleton
{
private:
	static CSingleton* mCSingleton;
	CSingleton() = default;

	CSingleton(const CSingleton& _Other) = delete;
	CSingleton(CSingleton&& _Other) noexcept = delete;
	CSingleton& operator=(const CSingleton& _Other) = delete;
	CSingleton& operator=(CSingleton&& _Other) noexcept = delete;

public:
	static CSingleton* GetSingleton()
	{
		if (nullptr == mCSingleton)
		{
			mCSingleton = new CSingleton();
		}

		return mCSingleton;
	}
};

CSingleton* CSingleton::mCSingleton = nullptr;

int main()
{
	CTest* a = new CTest();
	CTest* b = new CTest();
	CTest (CTest::*address)() = &CTest::Create;
	CSingleton* s = CSingleton::GetSingleton();
	int x = 0;
}
