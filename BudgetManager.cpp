#include "BudgetManager.h"
#include "UserManager.h"

BudgetManager::BudgetManager(){}

void BudgetManager::registerUser(){

    userManager.registerUser();

}

void BudgetManager::showAllUsers(){

    userManager.showAllUsers();

}

