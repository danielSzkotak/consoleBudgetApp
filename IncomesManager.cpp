#include "IncomesManager.h"


Income IncomesManager::provideNewIncomeData(){

    Income income;
    char choice;

    income.setIncomeId(incomesFile.getLastIncomeId() + 1);
    income.setUserId(LOGGED_USER_ID);

    choice = selectDate();

    switch (choice){

    case '1': income.setDate(date.getCurrentDate());
         break;
    case '2': {
         cout << "Podaj date w formacie RRRR-MM-DD: ";
         income.setDate(date.getSelectedDate());
         break;
    }
    }

    cout << "Podaj rodzaj przychodu: ";
    income.setItem(AuxiliaryMethods::readLine());

    cout << "Podaj kwote przychodu: ";
    income.setAmount(AuxiliaryMethods::readDouble());
    return income;

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
    cin.ignore();
    choice = AuxiliaryMethods::readCharacter();
    return choice;
}

void IncomesManager::addIncomeToTheConsoleTable(Income income){

       incomesConsoleTable.add( to_string(income.getIncomeId()) );
       incomesConsoleTable.add( income.getDate() );
       incomesConsoleTable.add( income.getItem() );
       incomesConsoleTable.add( AuxiliaryMethods::doubleToString(income.getAmount()) );
       incomesConsoleTable.endOfRow();
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

vector <Income> IncomesManager::getSortedPreviousMonthIncomes()
{
    vector <Income> previousMonthIncomes;
    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (AuxiliaryMethods::extractYearAndMonthFromDate(itr->getDate()) == date.getPreviousMonth())
        {
            previousMonthIncomes.push_back(*itr);
            totalIncomesAmount = totalIncomesAmount + (itr->getAmount());
        }
    }

    sort(previousMonthIncomes.begin(), previousMonthIncomes.end(), [](Income a, Income b) {
        return a.getDate() < b.getDate();
        });

    return previousMonthIncomes;
}

vector <Income> IncomesManager::getSortedSelectedDateIncomes(string startDate, string endDate)
{
    vector <Income> selectedDateIncomes;

    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if (((itr->getDate()) >= (startDate)) && ((itr->getDate()) <= (endDate)))
        {
            selectedDateIncomes.push_back(*itr);
            totalIncomesAmount = totalIncomesAmount + (itr->getAmount());
        }
    }

    sort(selectedDateIncomes.begin(), selectedDateIncomes.end(), [](Income a, Income b) {
        return a.getDate() < b.getDate();
        });

    return selectedDateIncomes;
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
           if (sortedCurrentMonthIncomes.size() == 0) {
            cout << "Brak przychodow z biezacego miesiaca" << endl;
           }

}

void IncomesManager::showPreviousMonthIncomes(){

       vector <Income> sortedPreviousMonthIncomes;
       totalIncomesAmount = 0;

       sortedPreviousMonthIncomes = getSortedPreviousMonthIncomes();

           cout << endl <<"PRZYCHODY Z POPRZEDNIEGO MIESIACA" << endl;
           incomesConsoleTable.add( "Id przychodu" );
           incomesConsoleTable.add( "Data dodania" );
           incomesConsoleTable.add( "Zrodlo przychodu" );
           incomesConsoleTable.add( "Kwota" );
           incomesConsoleTable.endOfRow();

            for (int i=0; i<sortedPreviousMonthIncomes.size(); i++){
                 addIncomeToTheConsoleTable(sortedPreviousMonthIncomes[i]);
            }

           cout << incomesConsoleTable;
           if (sortedPreviousMonthIncomes.size() == 0) {
            cout << "Brak przychodow z poprzedniego miesiaca" << endl;
           }
}

void IncomesManager::showSelectedDateIncomes(){

       vector <Income> sortedSelectedDateIncomes;
       totalIncomesAmount = 0;
       string startDate ="";
       string endDate ="";

       cout << "Podaj date poczatkowa w formacie RRRR-MM-DD: ";
       startDate = date.getSelectedDate();
        cout << "Podaj date koncowa w formacie RRRR-MM-DD: ";

       endDate = date.getSelectedDate();

       sortedSelectedDateIncomes = getSortedSelectedDateIncomes(startDate, endDate);

           cout << endl <<"PRZYCHODY ZE WSKAZANEGO OKRESU" << endl;
           incomesConsoleTable.add( "Id przychodu" );
           incomesConsoleTable.add( "Data dodania" );
           incomesConsoleTable.add( "Zrodlo przychodu" );
           incomesConsoleTable.add( "Kwota" );
           incomesConsoleTable.endOfRow();

            for (int i=0; i<sortedSelectedDateIncomes.size(); i++){
                 addIncomeToTheConsoleTable(sortedSelectedDateIncomes[i]);
            }

           cout << incomesConsoleTable;
           if (sortedSelectedDateIncomes.size() == 0) {
            cout << "Brak przychodow ze wskazanego okresu" << endl;
           }

}

double IncomesManager::getTotalIncomesAmount(){
    return totalIncomesAmount;
}
