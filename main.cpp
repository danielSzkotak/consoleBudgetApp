#include <iostream>
#include "BudgetManager.h"

using namespace std;

char selectOptionFromMainMenu();
char selectOptionFromUserMenu();

int main()
{

    BudgetManager budgetManager("users.xml", "incomes.xml", "expenses.xml");

    char choice {0};
    cin.clear();
    cin.sync();


    while (true)
    {
        if (!budgetManager.isUserLoggedIn())
        {
            choice = selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                budgetManager.registerUser();
                break;
            case '2':
                budgetManager.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else {

            choice = selectOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                budgetManager.addIncome();
                break;
            case '2':
                budgetManager.addExpense();
                break;
            case '3':
                budgetManager.showCurrentMonthBalance();
                break;
            case '4':
                budgetManager.showPreviousMonthBalance();
                break;
            case '5':
                budgetManager.showSelectedDateBalance();
                break;
            case '6':
                budgetManager.changeUserPassword();
                break;
            case '7':
                budgetManager.logOutUser();
                break;
            }
        }
    }
}

char selectOptionFromMainMenu()
{
    char choice {0};

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods::readCharacter();

    return choice;
}

char selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Pokaz bilans biezacego miesiaca" << endl;
    cout << "4. Pokaz bilans z poprzedniego miesiaca" << endl;
    cout << "5. Pokaz bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::readCharacter();

    return choice;
}

