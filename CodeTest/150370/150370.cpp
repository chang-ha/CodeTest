#include <string>
#include <vector>

using namespace std;

struct MyDate
{
    int Year = 0;
    int Month = 0;
    int Day = 0;

    bool operator >(const MyDate& _CompareDate)
    {
        if (this->Year < _CompareDate.Year)
        {
            return false;
        }
        else if (this->Year > _CompareDate.Year)
        {
            return true;
        }

        if (this->Month < _CompareDate.Month)
        {
            return false;
        }
        else if (this->Month > _CompareDate.Month)
        {
            return true;
        }

        if (this->Day < _CompareDate.Day)
        {
            return false;
        }
        else if (this->Day > _CompareDate.Day)
        {
            return true;
        }

        return false;
    }

    void AddMonth(const int _Month)
    {
        this->Month += _Month;
        this->Day -= 1;

        while (13 <= this->Month)
        {
            this->Month -= 12;
            this->Year += 1;
        }

        if (0 >= this->Day)
        {
            this->Day += 28;
            this->Month -= 1;
        }

        if (0 >= this->Month)
        {
            this->Month += 12;
            this->Year -= 1;
        }
    }
};

MyDate CreateDate(const std::string& _DateString)
{
    size_t YearPos = _DateString.find_first_of('.');
    size_t MonthPos = _DateString.find('.', YearPos + 1);
    size_t CheckDate = _DateString.find('.', MonthPos + 1);

    if (std::string::npos != CheckDate)
    {
        // Error
    }

    MyDate ResultDate;
    ResultDate.Year = std::stoi(_DateString.substr(0, YearPos));
    ResultDate.Month = std::stoi(_DateString.substr(YearPos + 1, MonthPos));
    ResultDate.Day = std::stoi(_DateString.substr(MonthPos + 1));
    return ResultDate;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;

    MyDate TodayDate = CreateDate(today);
    vector<int> TermsVector('Z' - 'A' + 1);

    for (const std::string& _CurTerms : terms)
    {
        size_t BlankSpace = _CurTerms.find(' ');
        TermsVector[_CurTerms[0] - 'A'] = std::stoi(_CurTerms.substr(BlankSpace + 1));
    }

    int Privacies_Size = static_cast<int>(privacies.size());
    for (int i = 0; i < Privacies_Size; ++i)
    {
        const std::string& _CurPrivacy = privacies[i];
        size_t BlankSpace = _CurPrivacy.find(' ');
        MyDate CurDate = CreateDate(_CurPrivacy.substr(0, BlankSpace));
        int Term = TermsVector[_CurPrivacy[BlankSpace + 1] - 'A'];
        CurDate.AddMonth(Term);

        if (TodayDate > CurDate)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

// 날짜 계산을 일수로도 해결가능
// Year = std::stoi(today.substr(0, 4)); Month = stoi(today.substr(5, 2)); Day = stoi(today.substr(8, 2));
// Total = Year * 12 * 28 + (Month - 1) * 28 + Day;