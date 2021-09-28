#ifndef XMLFILE_H
#define XMLFILE_H

#include "Markup.h"
#include "User.h"

#include <iostream>

using namespace std;

class XmlFile
{

    const string FILE_NAME;

    public:
        CMarkup xmlManager;
        XmlFile(string fileName) : FILE_NAME(fileName) {}

        string getFileName();
        bool isFileExists();


};

#endif // XMLFILE_H
