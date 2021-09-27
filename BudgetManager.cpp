#include "BudgetManager.h"
#include "UserManager.h"


void BudgetManager::registerUser(){

    userManager.registerUser();

}

bool BudgetManager::isUserLoggedIn(){

    return userManager.isUserLoggedIn();
}

void BudgetManager::logOutUser(){

    userManager.logOutUser();
    delete incomesManager;
    delete expensesManager;
    incomesManager = NULL;
    expensesManager = NULL;
}

void BudgetManager::logInUser(){

    userManager.logInUser();
    if (userManager.isUserLoggedIn()){

        incomesManager = new IncomesManager(INCOMES_FILE_NAME, userManager.getLoggedInUserId() );
        expensesManager = new ExpensesManager(EXPENSES_FILE_NAME, userManager.getLoggedInUserId());
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
       cout << endl << "BILANS PRZYCHODOW I ROZCHODOW" << endl;
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
       system("pause");
       //incomesManager->killTextTable();
}

void BudgetManager::showCurrentMonthBalance(){

    system("cls");
    incomesManager -> showCurrentMonthIncomes();
    expensesManager -> showCurrentMonthExpenses();
    showBalance();
}

void BudgetManager::showPreviousMonthBalance(){

    system("cls");
    incomesManager -> showPreviousMonthIncomes();
    expensesManager -> showPreviousMonthExpenses();
    showBalance();
}

void BudgetManager::showSelectedDateBalance(){

    system("cls");
    incomesManager ->showSelectedDateIncomes();
    expensesManager -> showSelectedDateExpenses();
    showBalance();
}

