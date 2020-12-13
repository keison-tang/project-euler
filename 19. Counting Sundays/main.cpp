/*
Problem 19: Counting Sundays

You are given the following information, but you may prefer to do some research for yourself.

- 1 Jan 1900 was a Monday.
- Thirty days has September, April, June and November.
- All the rest have thirty-one,
- Saving February alone, Which has twenty-eight, rain or shine. And on leap years, twenty-nine.
- A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <iostream>
#include <map>

bool IsLeapYear(int year) {
    if ((year % 4) == 0) { // divisible by 4?
        if ((year % 100) == 0) { // century?
            return (year % 400 == 0); // divisible by 400?
        } else {  
            return true;
        }
    }
    
    return false;
}

int main() {
    enum DayOfWeek { Mon, Tue, Wed, Thu, Fri, Sat, Sun };
    //enum Month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

    const std::map<int, int> daysPerMonthLookup = {
    {1, 31},
    //{2, 28},
    {3, 31},
    {4, 30},
    {5, 31},
    {6, 30},
    {7, 31},
    {8, 31},
    {9, 30},
    {10, 31},
    {11, 30},
    {12, 31}
    };

    struct date
    {
        int dayOfWeek;
        int day;
        int month;
        int year;
    } currentDate;
    
    currentDate.dayOfWeek = 1;
    currentDate.day = 1;
    currentDate.month = 1;
    currentDate.year = 1900;

    int sundays = 0;
    int daysInMonth = 0;

    while (currentDate.year != 2001) {
        //update currentDate
        
        //day of week: Sunday rolls around to Monday
        currentDate.dayOfWeek = currentDate.dayOfWeek == 7 ? 1 : currentDate.dayOfWeek + 1;
        
        //get days in month
        if (currentDate.month == 2) {
            if (IsLeapYear(currentDate.year)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
        } else {
            daysInMonth = daysPerMonthLookup.find(currentDate.month)->second;
        }

        //day and month update
        if (currentDate.day == daysInMonth) {   //last day of month
            currentDate.day = 1;
            currentDate.month = currentDate.month == 12 ? 1 : currentDate.month + 1; //dec roll around to jan
        } else {
            currentDate.day++;
        }
        
        //year: increment if it's now 1st Jan
        if (currentDate.day == 1 && currentDate.month == 1) {
            currentDate.year++;
        }

        //Check for Sundays that fell on 1st of the month during 1.1.1901 - 31.12.2000
        if ((currentDate.dayOfWeek == 7) && 
            (currentDate.day == 1) &&
            (currentDate.year >= 1901) &&
            (currentDate.year <= 2000)) {
                sundays++;
            }
    }

    std::cout << sundays << std::endl;

    return 0;
}