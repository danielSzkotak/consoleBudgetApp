#include "AuxiliaryMethods.h"
#include <iomanip>


AuxiliaryMethods::AuxiliaryMethods() {
    //ctor
}

string AuxiliaryMethods::intToString(int number) {

    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::readLine() {

    cin.sync();
    string input = "";
    getline(cin, input);
    return input;

}

double AuxiliaryMethods::readDouble() {

    regex numberValidation("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    smatch match;

    cin.sync();
    string input = "";
    double amountInDouble;

    while(true) {

        getline(cin, input);

        for (int i = 0; i < input.length(); i++) {
            if (input[i] == ',') {
                input[i] = '.';
            }
        }

        if (regex_match(input, match, numberValidation)) {

            amountInDouble = stringToDouble(input);
            return amountInDouble;
            break;

        } else {
            cout << endl << "Niepoprawna kwota, wprowadz jeszcze raz: ";
        }
    }

}


double AuxiliaryMethods::stringToDouble(string number) {

    double numberDouble;
    numberDouble = stod(number);

    return numberDouble;
}

string AuxiliaryMethods::doubleToString (double number) {

    ostringstream strs;
    strs << std::fixed;
    strs << std::setprecision(2);
    strs << number;
    string numberDouble = strs.str();
    return numberDouble;
}

int AuxiliaryMethods::stringToInt(string number) {

    int input;
    istringstream iss(number);
    iss >> input;

    return input;
}

char AuxiliaryMethods::readCharacter() {

    string input = "";
    char character = { 0 };

    while (true) {
        getline(cin, input);
        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }

    return character;

}

char AuxiliaryMethods::selectDate() {

    char choice;

    cout << "WYBIERZ DATE DODANIA PRZYCHODU " << endl;
    cout << "-------------------------------" << endl;
    cout << "1 - Dzisiejsza data" << endl;
    cout << "2 - Wybrana data" << endl;

    cout << endl << "Twoj wybor: ";
    choice = AuxiliaryMethods::readCharacter();
    return choice;

}

string AuxiliaryMethods::convertFirstLetterToApperCaseAndRestToLowerCase(string input) {

    if (!input.empty()) {
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        input[0] = toupper(input[0]);
    }
    return input;
}

