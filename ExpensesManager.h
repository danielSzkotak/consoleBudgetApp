#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include "Expense.h"
#include "ExpensesFile.h"
#include "Date.h"
#include "AuxiliaryMethods.h"
#include "IncomesManager.h"
#include "TextTable.h"

using namespace std;

class ExpensesManager
{
    const int LOGGED_USER_ID;
    vector<Expense> expenses;
    ExpensesFile expensesFile;
    double totalExpensesAmount;
    Expense provideNewExpenseData();
    void sortExpensesByDate();
    char selectDate();
    vector <Expense> getSortedCurrentMonthExpenses();
    vector <Expense> getSortedPreviousMonthExpenses();
    vector <Expense> getSortedSelectedDateExpenses();
    void addExpenseToTheConsoleTable(Expense expense);
    Date date;
    TextTable expensesConsoleTable;

    public:
        ExpensesManager(string expensesFileName, int loggedUserId) :
            expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId)
            {
                expenses = expensesFile.loadLoggedUserExpensesFromFile(LOGGED_USER_ID);
            };

        void addExpense();
        void showCurrentMonthExpenses();
        void showPreviousMonthExpenses();
        void showSelectedDateExpenses();
        double getTotalExpensesAmount();

};

#endif // EXPENSESMANAGER_H
