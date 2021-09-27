#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"
#include "TextTable.h"


using namespace std;

class BudgetManager {

    UserManager userManager;
    IncomesManager *incomesManager;
    ExpensesManager *expensesManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;
    void showBalance();

    public:
        BudgetManager(string usersFileName, string incomesFileName, string expensesFileName) :
            userManager(usersFileName),
            INCOMES_FILE_NAME(incomesFileName),
            EXPENSES_FILE_NAME(expensesFileName)
            {
                incomesManager = NULL;
                expensesManager = NULL;
            };
        ~BudgetManager(){
            delete incomesManager;
            delete expensesManager;
            incomesManager = NULL;
            expensesManager = NULL;
        }

        void registerUser();
        void logInUser();
        void logOutUser();
        bool isUserLoggedIn();
        void changeUserPassword();
        void showAllUsers();
        void addIncome();
        void addExpense();
        void showCurrentMonthBalance();
        void showPreviousMonthBalance();
        void showSelectedDateBalance();

};

#endif // BUDGETMANAGER_H
