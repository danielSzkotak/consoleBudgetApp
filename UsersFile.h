#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "XmlFile.h"

using namespace std;

class UsersFile : public XmlFile
{
    public:
        UsersFile(string fileName) : XmlFile(fileName){};


};

#endif // USERSFILE_H
