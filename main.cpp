#include <iostream>
#include "BudgetManager.h"

using namespace std;

int main()
{

    BudgetManager budgetManager("users.xml", "incomes.xml", "expenses.xml");
    //budgetManager.registerUser();
    budgetManager.logInUser();
   // budgetManager.addIncome();
   // budgetManager.addExpense();
    //budgetManager.showPreviousMonthBalance();
     budgetManager.showCurrentMonthBalance();

     //budgetManager.showSelectedDateBalance();

    return 0;
}
