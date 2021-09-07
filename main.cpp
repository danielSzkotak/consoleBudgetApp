#include <iostream>
#include "BudgetManager.h"

using namespace std;

int main()
{

    BudgetManager budgetManager("users.xml");
    //budgetManager.registerUser();
    budgetManager.logInUser();
    budgetManager.changeUserPassword();
    //budgetManager.showAllUsers();

    return 0;
}
