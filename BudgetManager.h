#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"


using namespace std;

class BudgetManager {

    UserManager userManager;

    public:
        BudgetManager();

        //virtual ~BudgetManager();
        void registerUser();

};

#endif // BUDGETMANAGER_H
