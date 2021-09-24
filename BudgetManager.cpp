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

void BudgetManager::showBalance(){

       TextTable balance;
       cout << endl <<"BILANS PRZYCHODOW I ROZCHODOW Z BIEZACEGO MIESIACA" << endl;
       balance.add( "Suma przychodow" );
       balance.add( AuxiliaryMethods::doubleToString(incomesManager ->getTotalIncomesAmount()) );
       balance.endOfRow();
       balance.add( "Suma rozchodow" );
       balance.add( AuxiliaryMethods::doubleToString(expensesManager ->getTotalExpensesAmount()) );
       balance.endOfRow();
       balance.add( "BILANS" );
       balance.add( AuxiliaryMethods::doubleToString((incomesManager ->getTotalIncomesAmount()) - (expensesManager ->getTotalExpensesAmount())));
       balance.endOfRow();
       cout << balance;
}

void BudgetManager::showCurrentMonthBalance(){

    incomesManager -> showCurrentMonthIncomes();
    expensesManager -> showCurrentMonthExpenses();
    showBalance();
}
