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

void IncomesManager::showIncome(Income income){

    cout << endl << "Id przychodu............." << to_string(income.getIncomeId()) << endl;
    cout << "Data dodania przychodu..." << income.getDate() << endl;
    cout << "Rodzaj przychodu........." << income.getItem() << endl;
    cout << "Kwota przychodu.........." << income.getAmount() << endl << endl;
}

void IncomesManager::showCurrentMonthIncomes(){

       vector <Income> currentMonthIncomes;

       for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if (itr->getDate().substr(0,7) == date.getCurrentMonth()){
                  currentMonthIncomes.push_back(*itr);
            }
        }

        sort(currentMonthIncomes.begin(), currentMonthIncomes.end(), [](Income a, Income b) {
        return a.getDate() < b.getDate();
        });

        for (int i=0; i<currentMonthIncomes.size(); i++){
             showIncome(currentMonthIncomes[i]);
        }

}

double IncomesManager::getTotalIncomesAmount(){


}
