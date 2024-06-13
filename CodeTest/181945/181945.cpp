#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
    string str;
    cin >> str;

    for (char _CurChar : str)
    {
        cout << _CurChar << endl;
    }

    return 0;
}