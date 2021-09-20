#include "ExpensesManager.h"


Expense ExpensesManager::provideNewExpenseData(){

    Expense expense;
    char choice;

    expense.setExpenseId(expensesFile.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_USER_ID);

    choice = selectDate();

    switch (choice){

    case '1': expense.setDate(date.getCurrentDate());
         break;
    case '2': expense.setDate(date.getSelectedDate());
         break;
    }

    cout << "Podaj rodzaj rozchodu: ";
    expense.setItem(AuxiliaryMethods::readLine());

    cout << "Podaj kwote rozchodu: ";
    expense.setAmount(AuxiliaryMethods::readDouble());
    return expense;

}

void ExpensesManager::sortExpensesByDate(){

}

void ExpensesManager::addExpense(){

    Expense expense;
    system("cls");
    cout << " >>> DODAWANIE ROZCHODU <<<" << endl << endl;

    expense = provideNewExpenseData();
    expenses.push_back(expense);
    if(expensesFile.addExpenseToFile(expense) == true){
        cout << endl << "DODANO ROZCHOD" << endl << endl;
        system("Pause");
    } else{
        cout << endl << "BLAD DODAWANIA ROZCHODU" << endl << endl ;
        system("Pause");
    }

}

char ExpensesManager::selectDate()
{
    char choice;


    cout << "WYBIERZ DATE DODANIA ROZCHODU " << endl;
    cout << "-------------------------------" << endl;
    cout << "1 - Dzisiejsza data" << endl;
    cout << "2 - Wybrana data" << endl;

    cout << endl << "Twoj wybor: ";
    choice = AuxiliaryMethods::readCharacter();

    return choice;
}

void ExpensesManager::showExpenses(){

}

double ExpensesManager::getTotalExpensesAmount(){


}
