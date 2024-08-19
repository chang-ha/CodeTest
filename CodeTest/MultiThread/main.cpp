#include <TimeCheck\TimeCheck.h>

#include <mutex>
#include <thread>
std::mutex mMutex;

static int Count = 0;

void InfinityLoop()
{
	mMutex.lock();
	Count++;
}

void DeadLock()
{
	std::thread InfinityThread(InfinityLoop);
	std::thread InfinityThread2(InfinityLoop);

	InfinityThread.join();
	InfinityThread2.join();
	Count++;
}

int main()
{
	int x = 0;
}