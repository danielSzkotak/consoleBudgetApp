#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class UserManager
{
    vector <User> users;
    User provideNewUserData();
    bool ifLoginExists(string login);

    public:
        UserManager();
        //virtual ~UserManager();
        void registerUser();
        void showAllUsers();

};

#endif // USERMANAGER_H
