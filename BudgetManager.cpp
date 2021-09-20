#include "BudgetManager.h"
#include "UserManager.h"


void BudgetManager::registerUser(){

    userManager.registerUser();

}

void BudgetManager::logInUser(){

    userManager.logInUser();
    if (userManager.ifUserIsLoggedIn()){

        incomesManager = new IncomesManager(INCOMES_FILE_NAME, userManager.getLoggedInUserId() );
        expensesManager = new ExpensesManager(EXPENSES_FILE_NAME, userManager.getLoggedInUserId() );
    }

}

void BudgetManager::changeUserPassword(){

    userManager.changeUserPassword();
}

void BudgetManager::showAllUsers(){

    userManager.showAllUsers();

}

void BudgetManager::addIncome(){

    incomesManager ->addIncome();
}


void BudgetManager::addExpense(){

    expensesManager ->addExpense();
}

