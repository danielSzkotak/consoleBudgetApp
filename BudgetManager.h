#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"


using namespace std;

class BudgetManager {

    UserManager userManager;
    IncomesManager *incomesManager;
    ExpensesManager *expensesManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

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
        void changeUserPassword();
        void showAllUsers();
        void addIncome();
        void addExpense();

};

#endif // BUDGETMANAGER_H
