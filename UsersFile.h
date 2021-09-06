#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "XmlFile.h"
#include "User.h"

using namespace std;

class UsersFile : public XmlFile
{
    public:
        UsersFile(string fileName) : XmlFile(fileName){};
        void addUserToFile(User user);
        vector<User> getUsersFromFile();


};

#endif // USERSFILE_H
