#include <iostream>
#include <string>

// C
// #include <stdio.h>
//#define LEN_INPUT 21
//
//int main(void) {
//    char s1[LEN_INPUT];
//
//	if (0 == scanf_s("%s", s1, static_cast<unsigned int>(sizeof(s1))))
//	{
//		// Error
//	}
//
//	int CharSize = 0;
//	while (0 != s1[CharSize])
//	{
//		char& CurChar = s1[CharSize];
//		if ('a' <= CurChar && 'z' >= CurChar)
//		{
//			CurChar = 'A' + (CurChar - 'a');
//		}
//		else if ('A' <= CurChar && 'Z' >= CurChar) 
//		{
//			CurChar = 'a' + (CurChar - 'A');
//		}
//		else
//		{
//			continue;
//		}
//		++CharSize;
//	}
//
//	printf_s("%s", s1);
//
//    return 0;
//}

int main()
{
    std::string str;
    std::cin >> str;

    size_t StringSize = str.size();

    for (char& _CurChar : str)
    {
        if (0 != std::isupper(_CurChar))
        {
            _CurChar = std::tolower(_CurChar);
        }
        else if (0 != std::islower(_CurChar))
        {
            _CurChar = std::toupper(_CurChar);
        }
    }

    std::cout << str << std::endl;

    return 0;
}