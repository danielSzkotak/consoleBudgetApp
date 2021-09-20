#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction
{
    int userId;
    string date;
    string item;
    double amount;

    public:
        Transaction();
        void setUserId(int id);
        void setDate(string newDate);
        void setItem(string newItem);
        void setAmount(double newAmount);
        int getUserId();
        string getDate();
        string getItem();
        double getAmount();

};

#endif // TRANSACTION_H
