#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

class Date
{
    private:

        static int month_days[12];
        static bool isLeapYear(int y);

    public:

        Date();
        static bool isDateValidFormat(string date);
        static string getCurrentDate();
        static string getSelectedDate();
        static string getCurrentMonth();
        static string getPreviousMonth();
        static string getDateWithFirstDayOfCurrentMonth();
        static string getDateWithLastDayOfCurrentMonth();
        static string getDateWithFisrtDayOfPreviousMonth();
        static string getDateWithLastDayOfPreviousMonth();
        //bool ifDatesAreTheSame(string date1, string date2);

};

#endif // DATE_H
