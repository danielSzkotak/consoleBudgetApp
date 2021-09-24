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

void ExpensesManager::addExpenseToTheConsoleTable(Expense expense){

       expensesConsoleTable.add( to_string(expense.getExpenseId()) );
       expensesConsoleTable.add( expense.getDate() );
       expensesConsoleTable.add( expense.getItem() );
       expensesConsoleTable.add( AuxiliaryMethods::doubleToString(expense.getAmount()) );
       expensesConsoleTable.endOfRow();
}

vector <Expense> ExpensesManager::getSortedCurrentMonthExpenses()
{
    vector <Expense> currentMonthExpenses;
    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if (AuxiliaryMethods::extractYearAndMonthFromDate(itr->getDate()) == date.getCurrentMonth())
        {
            currentMonthExpenses.push_back(*itr);
            totalExpensesAmount = totalExpensesAmount + (itr->getAmount());
        }
    }

    sort(currentMonthExpenses.begin(), currentMonthExpenses.end(), [](Expense a, Expense b) {
        return a.getDate() < b.getDate();
        });

    return currentMonthExpenses;
}

vector <Expense> ExpensesManager::getSortedPreviousMonthExpenses()
{
    vector <Expense> previousMonthExpenses;
    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if (AuxiliaryMethods::extractYearAndMonthFromDate(itr->getDate()) == date.getPreviousMonth())
        {
            previousMonthExpenses.push_back(*itr);
            totalExpensesAmount = totalExpensesAmount + (itr->getAmount());
        }
    }

    sort(previousMonthExpenses.begin(), previousMonthExpenses.end(), [](Expense a, Expense b) {
        return a.getDate() < b.getDate();
        });

    return previousMonthExpenses;
}

void ExpensesManager::showCurrentMonthExpenses(){

       vector <Expense> sortedCurrentMonthExpenses;
       totalExpensesAmount = 0;

       sortedCurrentMonthExpenses = getSortedCurrentMonthExpenses();

       cout << endl <<"ROZCHODY Z BIEZACEGO MIESIACA" << endl;
       expensesConsoleTable.add( "Id rozchodu" );
       expensesConsoleTable.add( "Data dodania" );
       expensesConsoleTable.add( "Zrodlo rozchodu" );
       expensesConsoleTable.add( "Kwota" );
       expensesConsoleTable.endOfRow();

        for (int i=0; i<sortedCurrentMonthExpenses.size(); i++){
             addExpenseToTheConsoleTable(sortedCurrentMonthExpenses[i]);
        }

       cout << expensesConsoleTable;
       if (sortedCurrentMonthExpenses.size() == 0) {
            cout << "Brak przychodow z poprzedniego miesiaca" << endl;
           }
}

void ExpensesManager::showPreviousMonthExpenses(){

       vector <Expense> sortedPreviousMonthExpenses;
       totalExpensesAmount = 0;

       sortedPreviousMonthExpenses = getSortedPreviousMonthExpenses();

       cout << endl <<"ROZCHODY Z POPRZEDNIEGO MIESIACA" << endl;
       expensesConsoleTable.add( "Id rozchodu" );
       expensesConsoleTable.add( "Data dodania" );
       expensesConsoleTable.add( "Zrodlo rozchodu" );
       expensesConsoleTable.add( "Kwota" );
       expensesConsoleTable.endOfRow();

        for (int i=0; i<sortedPreviousMonthExpenses.size(); i++){
             addExpenseToTheConsoleTable(sortedPreviousMonthExpenses[i]);
        }

       cout << expensesConsoleTable;
       if (sortedPreviousMonthExpenses.size() == 0) {
            cout << "Brak przychodow z poprzedniego miesiaca" << endl;
           }
}

double ExpensesManager::getTotalExpensesAmount(){
    return totalExpensesAmount;
}
