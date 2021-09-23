#include "IncomesManager.h"
#include <algorithm>


Income IncomesManager::provideNewIncomeData(){

    Income income;
    char choice;

    income.setIncomeId(incomesFile.getLastIncomeId() + 1);
    income.setUserId(LOGGED_USER_ID);

    choice = selectDate();

    switch (choice){

    case '1': income.setDate(date.getCurrentDate());
         break;
    case '2': income.setDate(date.getSelectedDate());
         break;
    }

    cout << "Podaj rodzaj przychodu: ";
    income.setItem(AuxiliaryMethods::readLine());

    cout << "Podaj kwote przychodu: ";
    income.setAmount(AuxiliaryMethods::readDouble());
    return income;

}

void IncomesManager::sortIncomesByDate(){

}

void IncomesManager::addIncome(){

    Income income;
    system("cls");
    cout << " >>> DODAWANIE PRZYCHODU <<<" << endl << endl;
    income = provideNewIncomeData();
    incomes.push_back(income);
    if(incomesFile.addIncomeToFile(income) == true){
        cout << endl << "DODANO PRZYCHOD" << endl << endl;
        system("Pause");
    } else{
        cout << endl << "BLAD DODAWANIA PRZUCHODU" << endl << endl ;
        system("Pause");

    }

}

char IncomesManager::selectDate()
{
    char choice;

    cout << "WYBIERZ DATE DODANIA PRZYCHODU " << endl;
    cout << "-------------------------------" << endl;
    cout << "1 - Dzisiejsza data" << endl;
    cout << "2 - Wybrana data" << endl;

    cout << endl << "Twoj wybor: ";
    choice = AuxiliaryMethods::readCharacter();

    return choice;
}

void IncomesManager::addIncomeToTheConsoleTable(Income income){

       incomesConsoleTable.add( to_string(income.getIncomeId()) );
       incomesConsoleTable.add( income.getDate() );
       incomesConsoleTable.add( income.getItem() );
       incomesConsoleTable.add( AuxiliaryMethods::doubleToString(income.getAmount()) );
       incomesConsoleTable.endOfRow();
       //t.setAlignment( 2, TextTable::Alignment::RIGHT );
}

vector <Income> IncomesManager::getSortedCurrentMonthIncomes()
{
    vector <Income> currentMonthIncomes;
    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (AuxiliaryMethods::extractYearAndMonthFromDate(itr->getDate()) == date.getCurrentMonth())
        {
            currentMonthIncomes.push_back(*itr);
            totalIncomesAmount = totalIncomesAmount + (itr->getAmount());
        }
    }

    sort(currentMonthIncomes.begin(), currentMonthIncomes.end(), [](Income a, Income b) {
        return a.getDate() < b.getDate();
        });

    return currentMonthIncomes;
}


void IncomesManager::showCurrentMonthIncomes(){

       vector <Income> sortedCurrentMonthIncomes;
       totalIncomesAmount = 0;

       sortedCurrentMonthIncomes = getSortedCurrentMonthIncomes();

       cout << endl <<"PRZYCHODY Z BIEZACEGO MIESIACA" << endl;
       incomesConsoleTable.add( "Id przychodu" );
       incomesConsoleTable.add( "Data dodania" );
       incomesConsoleTable.add( "Zrodlo przychodu" );
       incomesConsoleTable.add( "Kwota" );
       incomesConsoleTable.endOfRow();

        for (int i=0; i<sortedCurrentMonthIncomes.size(); i++){
             addIncomeToTheConsoleTable(sortedCurrentMonthIncomes[i]);
        }

       cout << incomesConsoleTable;
}

double IncomesManager::getTotalIncomesAmount(){
    return totalIncomesAmount;
}
