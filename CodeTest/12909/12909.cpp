#include<string>
#include <iostream>

using namespace std;

#include <stack>
#include <stdexcept>
bool ssolution(string s)
{
	std::stack<char> CharStack;

	for (const char CurChar : s)
	{
		switch (CurChar)
		{
		case '(':
			CharStack.push(CurChar);
			break;
		case ')':
			if (false == CharStack.empty())
			{
				CharStack.pop();
			}
			else
			{
				return false;
			}
			break;
		default:
			throw std::invalid_argument("argument must be ( or )");
		}
	}

	return false == CharStack.empty() ? false : true;
}

bool solution(string s)
{
	std::stack<char> CharStack;

	for (const char CurChar : s)
	{
		if (true == CharStack.empty())
		{
			CharStack.push(CurChar);
			continue;
		}

		switch (CurChar)
		{
		case '(':
			CharStack.push(CurChar);
			break;
		case ')':
			if ('(' == CharStack.top())
			{
				CharStack.pop();
			}
			else
			{
				return false;
			}
			break;
		default:
			throw std::invalid_argument("argument must be ( or )");
		}
	}

	return false == CharStack.empty() ? false : true;
}