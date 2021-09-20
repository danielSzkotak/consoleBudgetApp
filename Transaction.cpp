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

void Transaction::setItem(string newItem){

    item = newItem;
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

string Transaction::getItem(){
    return item;
}

double Transaction::getAmount(){
    return amount;
}

