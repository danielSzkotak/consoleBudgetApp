#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Expense.h"
#include "ExpensesFile.h"
#include "Date.h"
#include "AuxiliaryMethods.h"

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
    Date date;

    public:
        ExpensesManager(string expensesFileName, int loggedUserId) :
            expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId)
            {
                expenses = expensesFile.loadLoggedUserExpensesFromFile(LOGGED_USER_ID);
            };

        void addExpense();
        void showExpenses();
        double getTotalExpensesAmount();

};

#endif // EXPENSESMANAGER_H
