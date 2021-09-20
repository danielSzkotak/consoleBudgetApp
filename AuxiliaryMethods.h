#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <string.h>

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

};

#endif // AUXILIARYMETHODS_H
