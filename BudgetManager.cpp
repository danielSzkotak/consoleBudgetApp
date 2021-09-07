#include "BudgetManager.h"
#include "UserManager.h"


void BudgetManager::registerUser(){

    userManager.registerUser();

}

void BudgetManager::logInUser(){

    userManager.logInUser();

}

void BudgetManager::changeUserPassword(){

    userManager.changeUserPassword();
}

void BudgetManager::showAllUsers(){

    userManager.showAllUsers();

}

