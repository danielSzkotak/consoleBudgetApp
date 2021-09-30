#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <regex>

using namespace std;

class AuxiliaryMethods
{
    public:
        AuxiliaryMethods();
        static string intToString(int number);
        static string readLine();
        static double readDouble();
        static string doubleToString(double number);
        static double stringToDouble(string number);
        static int stringToInt(string number);
        static char readCharacter();
        static char selectDate();
        static string convertFirstLetterToApperCaseAndRestToLowerCase(string input);

};

#endif // AUXILIARYMETHODS_H
