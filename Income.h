#ifndef INCOME_H
#define INCOME_H
#include "Transaction.h"

#include <iostream>

using namespace std;

class Income : public Transaction
{

    int incomeId;

    public:
        Income();
        void setIncomeId(int id);
        int getIncomeId();

};

#endif // INCOME_H
