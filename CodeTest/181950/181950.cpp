#include <iostream>
#include <string>

using namespace std;

class RepeatString
{
public:
    RepeatString(std::string _String, int _RepeatNumber)
        : String(_String), RepeatNumber(_RepeatNumber)
    {

    }

    RepeatString() = default;
    ~RepeatString() = default;
private:
    std::string String = "";
    int RepeatNumber = 0;

    // friend
    friend std::istream& operator>>(std::istream& _Input, RepeatString& _RepeatString);
    friend std::ostream& operator<<(std::ostream& _Output, const RepeatString& _RepeatString);
};

int main(void) 
{
    RepeatString InputValue;
    std::cin >> InputValue;
    std::cout << InputValue;
    return 0;
}

std::istream& operator>>(std::istream& _Input, RepeatString& _RepeatString)
{
    _Input >> _RepeatString.String >> _RepeatString.RepeatNumber;
    return _Input;
}

std::ostream& operator<<(std::ostream& _Output, const RepeatString& _RepeatString)
{
    std::string tRepeatString;
    tRepeatString.reserve(_RepeatString.String.size() * _RepeatString.RepeatNumber);

    for (size_t i = 0; i < _RepeatString.RepeatNumber; i++)
    {
        tRepeatString += _RepeatString.String;
    }

    _Output << tRepeatString << std::endl;
    return _Output;
}

// Compiler Version Problem
//#include <sstream>
//
//std::ostream& operator<<(std::ostream& _Output, const RepeatString& _RepeatString)
//{
//    std::ostringstream RepeatString;
//    fill_n(std::ostream_iterator<std::string>(RepeatString), _RepeatString.RepeatNumber, _RepeatString.String);
//    std::cout << RepeatString.str() << std::endl;
//    return _Output;
//}