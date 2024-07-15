#include <string>
#include <vector>

using namespace std;


#include <string>
#include <vector>

using namespace std;

vector<int> Othersolution(int n) 
{
	std::vector<int> answer;
	answer.push_back(n);
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else n = 3 * n + 1;
		answer.push_back(n);
	}
	return answer;
}

vector<int> solution(int n)
{
	std::vector<int> answer;

	while (n != 1)
	{
		answer.push_back(n);
		switch (n % 2)
		{
		case 0:
			// Â¦¼ö
			n /= 2;
			break;
		case 1:
			// È¦¼ö
			n = 3 * n + 1;
			break;
		default:
			// Error
			answer.clear();
			break;
		}
	}
	answer.push_back(1);

	return answer;
}

#include <list>
list<int> listsolution(int n)
{
	std::list<int> answer;

	while (n != 1)
	{
		answer.push_back(n);
		switch (n % 2)
		{
		case 0:
			// Â¦¼ö
			n /= 2;
			break;
		case 1:
			// È¦¼ö
			n = 3 * n + 1;
			break;
		default:
			// Error
			answer.clear();
			break;
		}
	}
	answer.push_back(1);

	return answer;
}

#include <deque>
deque<int> dequesolution(int n)
{
	std::deque<int> answer;

	while (n != 1)
	{
		answer.push_back(n);
		switch (n % 2)
		{
		case 0:
			// Â¦¼ö
			n /= 2;
			break;
		case 1:
			// È¦¼ö
			n = 3 * n + 1;
			break;
		default:
			// Error
			answer.clear();
			break;
		}
	}
	answer.push_back(1);

	return answer;
}
