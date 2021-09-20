#ifndef EXPENSE_H
#define EXPENSE_H
#include "Transaction.h"

#include <iostream>

using namespace std;

class Expense : public Transaction
{
    int expenseId;

    public:

        void setExpenseId(int id);
        int getExpenseId();
};

#endif // EXPENSE_H
