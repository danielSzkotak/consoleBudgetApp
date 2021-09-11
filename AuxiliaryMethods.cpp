#include "AuxiliaryMethods.h"

AuxiliaryMethods::AuxiliaryMethods()
{
    //ctor
}

string AuxiliaryMethods::intToString(int number) {

    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
