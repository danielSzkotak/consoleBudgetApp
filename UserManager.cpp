#include "UserManager.h"

UserManager::UserManager(){}

void UserManager::registerUser(){


    User user = provideNewUserData();
    users.push_back(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");

}

bool UserManager::ifLoginExists(string login){

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {

            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;
}

User UserManager::provideNewUserData(){

    User user;
    user.setUserId(1);
    //uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);


    } while (ifLoginExists(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Podaj Imie: ";
    cin >> name;
    user.setName(name);

    string surName;
    cout << "Podaj Nazwisko: ";
    cin >> surName;
    user.setSurname(surName);

    return user;
}

void UserManager::showAllUsers(){

    for (int i = 0; i < users.size(); i++) {

        cout << users[i].getUserId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}
