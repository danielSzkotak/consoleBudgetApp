#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"


using namespace std;

class BudgetManager {

    UserManager userManager;

    public:
        BudgetManager(string usersFileName) : userManager(usersFileName) {};

        //virtual ~BudgetManager();
        void registerUser();
        void logInUser();
        void changeUserPassword();
        void showAllUsers();

};

#endif // BUDGETMANAGER_H
