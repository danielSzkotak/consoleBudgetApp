#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UsersFile.h"
#include <string>
#include <cstdlib>

using namespace std;

class UserManager
{
    vector <User> users;
    UsersFile usersFile;
    int loggedUserId;

    User provideNewUserData();
    bool ifLoginExists(string login);
    int getNewUserId();

    public:
        UserManager(string usersFileName) : usersFile(usersFileName) {

            users = usersFile.getUsersFromFile();
            loggedUserId = 0;
        };

        void registerUser();
        int logInUser();
        int getLoggedInUserId();
        bool isUserLoggedIn();
        void changeUserPassword();
        void logOutUser();
        void showAllUsers();

};

#endif // USERMANAGER_H
