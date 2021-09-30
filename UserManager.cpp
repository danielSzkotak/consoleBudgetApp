#include "UserManager.h"
#include "UsersFile.h"


void UserManager::registerUser() {


    User user = provideNewUserData();
    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");

}

bool UserManager::ifLoginExists(string login) {

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {

            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;
}

int UserManager::getNewUserId() {

    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

User UserManager::provideNewUserData() {

    User user;
    user.setUserId(getNewUserId());
    string login;

    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);


    } while (ifLoginExists(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    cout << "Podaj Imie: ";
    user.setName(AuxiliaryMethods::convertFirstLetterToApperCaseAndRestToLowerCase(AuxiliaryMethods::readLine()));

    cout << "Podaj Nazwisko: ";
    user.setSurname(AuxiliaryMethods::convertFirstLetterToApperCaseAndRestToLowerCase(AuxiliaryMethods::readLine()));

    return user;
}


int UserManager::logInUser() {

    string login = "", passwd = "";

    cout << "Podaj login: ";
    cin >> login;

    for (int i = 0; i < users.size(); i++) {

        if (users[i].getLogin() == login) {

            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                cin >> passwd; //passwd = MetodyPomocnicze::wczytajLinie();

                if (users[i].getPassword() == passwd) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return loggedUserId = users[i].getUserId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;

        }
    }

    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

int UserManager::getLoggedInUserId() {

    return loggedUserId;
}

bool UserManager::isUserLoggedIn() {

    if (loggedUserId != 0)
        return true;
    else
        return false;
}

void UserManager::changeUserPassword() {

    string newPassword = "";
    cout << " >>> ZMIANA HASLA <<<" << endl << endl;
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr->getUserId() == loggedUserId) {
            itr->setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    usersFile.saveNewPasswordToFile(newPassword, loggedUserId);
    //plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);

}

void UserManager::logOutUser() {

    loggedUserId = 0;
    cout << "Wylogowales sie" << endl << endl;
    system("pause");
}
