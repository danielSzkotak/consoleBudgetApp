#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "IncomesManager.h"


using namespace std;

class BudgetManager {

    UserManager userManager;
    IncomesManager *incomesManager;
    const string INCOMES_FILE_NAME;

    public:
        BudgetManager(string usersFileName, string incomesFileName) :
            userManager(usersFileName),
            INCOMES_FILE_NAME(incomesFileName)
            {
                incomesManager = NULL;
            };
        ~BudgetManager(){
            delete incomesManager;
            incomesManager = NULL;
        }

        //virtual ~BudgetManager();
        void registerUser();
        void logInUser();
        void changeUserPassword();
        void showAllUsers();
        void addIncome();

};

#endif // BUDGETMANAGER_H
