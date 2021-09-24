#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

class Date
{
    private:

        int month_days[12];
        bool isLeapYear(int y);

    public:

        Date(){

            month_days[0] = 31;  month_days[1] = 28;  month_days[2] = 31; month_days[3] = 30;
            month_days[4] = 31; month_days[5] = 30; month_days[6] = 31; month_days[7] = 31;
            month_days[8] = 30; month_days[9] = 31; month_days[10] = 30; month_days[11] = 31;

        }

        bool isDateValidFormat(string date);
        string getCurrentDate();
        string getSelectedDate();
        string getCurrentMonth();
        string getDateWithFirstDayOfCurrentMonth();
        string getDateWithLastDayOfCurrentMonth();
        string getDateWithFisrtDayOfPreviousMonth();
        string getDateWithLastDayOfPreviousMonth();
        bool ifDatesAreTheSame(string date1, string date2);

};

#endif // DATE_H
