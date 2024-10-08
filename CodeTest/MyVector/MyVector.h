#pragma once

#include <Windows.h>
#include <assert.h>
#include <stdexcept>
template <typename T>
class MyVector
{
public:
	MyVector() = default;
	MyVector(const size_t InSize)
	{
		mData = new T[InSize];
		mSize = InSize;
		mCapacity = InSize;
	}

	MyVector(const size_t InSize, const T& Value)
	{
		mData = new T[InSize];
		for (size_t i = 0; i < InSize; i++)
		{
			mData[i] = Value;
		}
		mSize = InSize;
		mCapacity = InSize;
	}

	~MyVector()
	{
		delete[] mData;
		mData = nullptr;
	}

	size_t size() const	{ return mSize; }
	size_t capacity() const { return mCapacity; }
	bool empty() const { return 0 == mSize; }
	void clear() { mSize = 0; }
	T& operator[] (const int Index) const { return mData[Index]; }
	T& at(const int Index) const
	{
		if (mSize <= Index)
		{
			throw std::out_of_range("out of vector size");
		}

		return mData[Index];
	}

	void push_back(const T& InData)
	{
		if (mSize + 1 > mCapacity)
		{
			ReAlloc();
		}

		mData[mSize] = InData;
		++mSize;
	}

	void pop_back()
	{
		if (0 == mSize)
		{
			MessageBoxA(nullptr, "vector is empty", "wrong function call", MB_OK);
			assert(false);
		}
		--mSize;
	}

	void reserve(const int Index)
	{
		if (mCapacity >= Index)
		{
			return;
		}

		ReAlloc(Index);
	}

protected:

private:
	void ReAlloc(const size_t InCapacity = 0)
	{
		if (0 == mCapacity)
		{
			mCapacity = 1;
		}
		else if (0 == InCapacity)
		{
			mCapacity *= 2;
		}
		else
		{
			mCapacity = InCapacity;
		}

		T* tData = new T[mCapacity];
		for (size_t i = 0; i < mSize; i++)
		{
			tData[i] = std::move(mData[i]);
		}

		delete[] mData;
		mData = tData;
	}

	size_t	mSize = 0;
	size_t	mCapacity = 0;
	T*		mData = nullptr;
};

