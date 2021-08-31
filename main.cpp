#include <iostream>
#include "BudgetManager.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    BudgetManager budgetManager;

    budgetManager.registerUser();
    budgetManager.registerUser();
    budgetManager.showAllUsers();

    return 0;
}
