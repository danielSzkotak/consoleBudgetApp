#include "XmlFile.h"
#include <fstream>

string XmlFile::getFileName(){

    return FILE_NAME;
}

bool XmlFile::ifFileExists(){

    ifstream infile(FILE_NAME);
    return infile.good();
}
