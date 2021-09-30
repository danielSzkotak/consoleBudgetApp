#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

class Date
{
    private:

        static bool isLeapYear(int y);

    public:

        Date();
        static bool isDateValidFormat(string date);
        static string getCurrentDate();
        static string getSelectedDate();
        static string extractYearAndMonthFromDate(string inputDate);
        static string getPreviousMonthDate();

};

#endif // DATE_H
