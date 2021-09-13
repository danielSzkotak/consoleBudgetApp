#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include "Income.h"
#include <string>


using namespace std;

class IncomesFile : public XmlFile
{

    int lastIncomeId;

    public:
        IncomesFile(string fileName) : XmlFile(fileName)
        {
            lastIncomeId = 0;
        };

        int getLastIncomeId();
        vector<Income> loadLoggedUserIncomesFromFile(int loggedUserId);
        void addIncomeToFile();

};

#endif // INCOMESFILE_H
