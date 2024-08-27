#include <vector>
#include <thread>
#include <functional>
#include <condition_variable>
#include <future>

class ThreadPool
{
public:
	ThreadPool(size_t);
	~ThreadPool() = default;

	template<class F, class... Args>
	auto enqueue(F&& f, Args&&... args) 
		-> std::future<typename std::result_of<F(Args...)>::type>; // 후행 반환 형식
private:
	std::vector<std::thread> Workers;
	std::condition_variable condition;
	bool Stop;
};

int main()
{

}

inline ThreadPool::ThreadPool(size_t thread_count)
	: Stop(false)
{
	for (size_t i = 0; i < thread_count; i++)
	{
		Workers.emplace_back([this]()
			{
				for (;;)
				{
					std::function<void()> task;

					{
						std::unique_lock<std::mutex> lock();
					}
				}
			});
	}
}

template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args)
	-> std::future<typename std::result_of<F(Args...)>::type>
{
	using returntype = typename std::result_of<F(Args...)>::type;


}