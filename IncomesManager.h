#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <vector>
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
    void sortIncomesByDate();
    char selectDate();
    vector <Income> getSortedCurrentMonthIncomes();
    void addIncomeToTheConsoleTable(Income income);
    Date date;
    TextTable incomesConsoleTable;

    public:
        IncomesManager(string incomesFileName, int loggedUserId) :
            incomesFile(incomesFileName), LOGGED_USER_ID(loggedUserId)
            {
                incomes = incomesFile.loadLoggedUserIncomesFromFile(LOGGED_USER_ID);
            };

        void addIncome();
        void showCurrentMonthIncomes();
        double getTotalIncomesAmount();

};

#endif // INCOMESMANAGER_H
