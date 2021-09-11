#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction
{
    int userId;
    string date;
    string type;
    double amount;

    public:
        Transaction();
        void setUserId(int id);
        void setDate(string newDate);
        void setType(string newType);
        void setAmount(double newAmount);
        int getUserId();
        string getDate();
        string getType();
        double getAmount();

};

#endif // TRANSACTION_H
