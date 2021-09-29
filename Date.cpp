#include "Date.h"

#include <iostream>
#include <string>
#include <regex>

using namespace std;

//int Date::month_days[12];


//Date::Date(){}

bool Date::isLeapYear(int y){

    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    if (y % 4 == 0) return true;
    return false;
}

bool Date::isDateValidFormat(string date){

   int month_days[12] = {31,28, 31,30,31,30,31,31,30,31,30,31};

   regex dateFormat("^((?:19|20)[0-9][0-9])-(0?[1-9]|1[012])-(0?[1-9]|[12][0-9]|3[01])$");
   smatch match;

   if (regex_match(date, match, dateFormat)){

       string strYear = match[1];
       int year = atoi(strYear.c_str());
       string strMonth = match[2];
       int month = atoi(strMonth.c_str());
       string strDay = match[3];
       int day = atoi(strDay.c_str());

       if (year < 2000) return false;
       if ((isLeapYear(year)) && (month == 2) && (day > 29)) return false;
       if ((!isLeapYear(year)) && (day > month_days[month - 1])) return false;
       if ((isLeapYear(year)) && (month != 2) && (day > month_days[month - 1])) return false;

       return true;

   } else return false;

}

string Date::getCurrentDate(){

    const int MAXLEN = 80;
    char s[MAXLEN];
    time_t t = time(0);
    strftime(s, MAXLEN, "%Y-%m-%d", localtime(&t));
    return s;
}

string Date::getCurrentMonth(){

    return getCurrentDate().substr(0,7);
}


string Date::getSelectedDate(){

    string inputDate="";
    while (true)
    {
        inputDate = AuxiliaryMethods::readLine();

        if (Date::isDateValidFormat(inputDate))
        {
            return inputDate;
        }
        else
        {
            cout << endl << "Wprowadzono nieprawidlowa date, sprobuj jeszcze raz: ";
        }
    }
}


string Date::getPreviousMonthDate(){

    string previousMonthStr="";
    int previousMonth = (stoi(getCurrentDate().substr(5,2))) - 1;

    if (previousMonth > 9) previousMonthStr = to_string(previousMonth);
    if (previousMonth < 9 && previousMonth != 0) previousMonthStr = "0" + to_string(previousMonth);
    if (previousMonth == 0) {

            int previousYear = stoi(getCurrentDate().substr(0,4))-1;
            return to_string(previousYear) + "-12-01";
    }
    string previousMontDate = getCurrentDate().replace(5,2, previousMonthStr);
    return previousMontDate.substr(0,7);
}





