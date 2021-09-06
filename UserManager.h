#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UsersFile.h"
#include <string>

using namespace std;

class UserManager
{
    vector <User> users;
    UsersFile usersFile;
    User provideNewUserData();
    bool ifLoginExists(string login);
    int getNewUserId();

    public:
        UserManager(string usersFileName) : usersFile(usersFileName) {

            users = usersFile.getUsersFromFile();
        };
        //virtual ~UserManager();
        void registerUser();
        void showAllUsers();

};

#endif // USERMANAGER_H
