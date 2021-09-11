#include "Transaction.h"

Transaction::Transaction()
{
    //ctor
}

void Transaction::setUserId(int id){

    if (id >= 0) userId = id;
}

void Transaction::setDate(string newDate){

    date = newDate;
}

void Transaction::setType(string newType){

    type = newType;
}

void Transaction::setAmount(double newAmount){

    amount = newAmount;
}

int Transaction::getUserId(){
    return userId;
}

string Transaction::getDate(){
    return date;
}

string Transaction::getType(){
    return date;
}

double Transaction::getAmount(){
    return amount;
}

