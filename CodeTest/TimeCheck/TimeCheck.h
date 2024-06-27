#pragma once
#include <chrono>
#include <functional>
#define TIME_UNIT std::chrono::microseconds

TIME_UNIT CheckFunctionTime(std::function<void()> _Function, int _RepeatTime)
{
	std::chrono::steady_clock::time_point Start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < _RepeatTime; i++)
	{
		_Function();
	}
	std::chrono::steady_clock::time_point End = std::chrono::high_resolution_clock::now();
	TIME_UNIT Result = std::chrono::duration_cast<TIME_UNIT>(End - Start);
	return Result;
}