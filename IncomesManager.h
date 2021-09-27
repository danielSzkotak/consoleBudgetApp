#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "Income.h"
#include "IncomesFile.h"
#include "Date.h"
#include "AuxiliaryMethods.h"
#include "TextTable.h"

using namespace std;

class IncomesManager
{
    const int LOGGED_USER_ID;
    vector<Income> incomes;
    IncomesFile incomesFile;
    double totalIncomesAmount;
    Income provideNewIncomeData();
    char selectDate();
    vector <Income> getSortedCurrentMonthIncomes();
    vector <Income> getSortedPreviousMonthIncomes();
    vector <Income> getSortedSelectedDateIncomes();
    void addIncomeToTheConsoleTable(Income income, TextTable& incomesConsoleTable);
    Date date;

    public:
        IncomesManager(string incomesFileName, int loggedUserId) :
            incomesFile(incomesFileName), LOGGED_USER_ID(loggedUserId)
            {
                incomes = incomesFile.loadLoggedUserIncomesFromFile(LOGGED_USER_ID);
            };
        static string startDate;
        static string endDate;
        void addIncome();
        void showCurrentMonthIncomes();
        void showPreviousMonthIncomes();
        void showSelectedDateIncomes();
        double getTotalIncomesAmount();
        static string getStartDate();
        static string getEndDate();


};

#endif // INCOMESMANAGER_H
