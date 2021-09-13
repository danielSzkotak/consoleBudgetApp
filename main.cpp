#include <iostream>
#include "BudgetManager.h"

using namespace std;

int main()
{

    BudgetManager budgetManager("users.xml", "incomes.xml");
    //budgetManager.registerUser();
    budgetManager.logInUser();
    budgetManager.addIncome();


    return 0;
}
