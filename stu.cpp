#include <iostream>
#include <vector>
#include <string>

class CDate
{
protected:
    int year;  // 年
    int month; // 月
    int day;   // 日

public:
    // 构造函数
    CDate(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}

    // 设置日期
    void setDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }

    // 增加一天日期
    void increaseDate()
    {
        day++;
        if (day > getDaysInMonth())
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
    }

    // 获取当前月份的天数
    int getDaysInMonth() const
    {
        static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = daysInMonth[month - 1];
        if (month == 2 && isLeapYear())
        {
            days++;
        }
        return days;
    }

    // 判断是否是闰年
    bool isLeapYear() const
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // 显示日期
    void showDate() const
    {
        std::cout << year << "/" << month << "/" << day << std::endl;
    }
};

class CDateMultiRegion : public CDate
{
private:
    std::string region; // 地区

public:
    // 构造函数
    CDateMultiRegion(int y = 0, int m = 0, int d = 0, const std::string &r = "") : CDate(y, m, d), region(r) {}

    // 重载显示日期
    void showDate() const
    {
        if (region == "uk")
        {
            std::cout << "uk " << day << "/" << month << "/" << year << std::endl;
        }
        else if (region == "cn")
        {
            std::cout << "cn " << year << "/" << month << "/" << day << std::endl;
        }
        else if (region == "us")
        {
            std::cout << "us " << month << "/" << day << "/" << year << std::endl;
        }
    }
};

int main()
{
    std::vector<CDateMultiRegion> dates;

    for (int i = 0; i < 3; i++)
    {
        int year, month, day;
        std::string region;

        std::cin >> year >> month >> day >> region;

        CDateMultiRegion date(year, month, day, region);
        date.increaseDate();
        dates.push_back(date);
    }

    for (std::vector<CDateMultiRegion>::iterator it = dates.begin(); it != dates.end(); ++it)
    {
        it->showDate();
    }

    return 0;
}
