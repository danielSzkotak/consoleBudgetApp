#include "AuxiliaryMethods.h"
#include <iomanip>


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

string AuxiliaryMethods::readLine()
{
    cin.sync();
    //cin.ignore();
    string input = "";
    getline(cin, input);
    return input;

}

double AuxiliaryMethods::readDouble()
{
    cin.sync();
    string input = "";
    double amountInDouble;
    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ',') {
            input[i] = '.';
        }
    }
    amountInDouble = stringToDouble(input);
    return amountInDouble;
}


double AuxiliaryMethods::stringToDouble(string number) {

    double numberDouble;
    numberDouble = stod(number);

    return numberDouble;
}

string AuxiliaryMethods::doubleToString (double number) {

    ostringstream strs;
    strs << number;
    setprecision(2);
    string numberDouble = strs.str();
    return numberDouble;
}

int AuxiliaryMethods::stringToInt(string number){

    int input;
    istringstream iss(number);
    iss >> input;

    return input;
}

char AuxiliaryMethods::readCharacter()
{
    string input = "";
    char character = { 0 };

    while (true)
    {
        getline(cin, input);
        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
          cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
   return character;
}

string AuxiliaryMethods::extractYearAndMonthFromDate(string inputDate){

    return inputDate.substr(0,7);
}

