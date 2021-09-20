#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include "XmlFile.h"
#include "Expense.h"
#include <string>
#include "AuxiliaryMethods.h"

using namespace std;

class ExpensesFile : public XmlFile
{

    int lastExpenseId;

    public:
        ExpensesFile(string fileName) : XmlFile(fileName)
        {
            lastExpenseId = 0;
        };

        int getLastExpenseId();
        vector<Expense> loadLoggedUserExpensesFromFile(int loggedUserId);
        bool addExpenseToFile(Expense expense);

};

#endif // EXPENSESFILE_H
