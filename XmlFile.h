#ifndef XMLFILE_H
#define XMLFILE_H

#include "Markup.h"

#include <iostream>

using namespace std;

class XmlFile
{

    const string FILE_NAME;

    public:
        XmlFile(string fileName) : FILE_NAME(fileName) {};
        CMarkup xmlManager;
        string getFileName();
        bool ifFileExists();


};

#endif // XMLFILE_H
