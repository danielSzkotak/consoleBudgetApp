#include "XmlFile.h"
#include <fstream>

string XmlFile::getFileName(){

    return FILE_NAME;
}

bool XmlFile::isFileExists(){

    ifstream infile(FILE_NAME);
    return infile.good();
}
