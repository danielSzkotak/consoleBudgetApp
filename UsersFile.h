#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "XmlFile.h"
#include "User.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class UsersFile : public XmlFile
{


    public:
        UsersFile(string fileName) : XmlFile(fileName){};
        void addUserToFile(User user);
        vector<User> getUsersFromFile();
        void saveNewPasswordToFile(string newPassword, int loggedUserId);
        string intToString(int number);


};

#endif // USERSFILE_H
