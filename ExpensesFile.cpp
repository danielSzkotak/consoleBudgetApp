#include "ExpensesFile.h"


int ExpensesFile::getLastExpenseId(){

 return lastExpenseId;
}

vector<Expense> ExpensesFile::loadLoggedUserExpensesFromFile(int loggedUserId){

Expense expense;
vector<Expense> expenses;

    string dane = "";
    xmlManager.Load(getFileName());
    xmlManager.ResetPos();

    if (isFileExists()) {

        xmlManager.FindElem("EXPENSES");
        xmlManager.IntoElem();

        while (xmlManager.FindElem("EXPENSE")) {

            xmlManager.IntoElem();
            xmlManager.FindElem("userId");

            if (AuxiliaryMethods::stringToInt(xmlManager.GetData()) == loggedUserId) {

                expense.setUserId(loggedUserId);
                xmlManager.FindElem("expenseId");
                expense.setExpenseId(AuxiliaryMethods::stringToInt(xmlManager.GetData()));
                xmlManager.FindElem("date");
                expense.setDate(xmlManager.GetData());
                xmlManager.FindElem("item");
                expense.setItem(xmlManager.GetData());
                xmlManager.FindElem("amount");
                expense.setAmount(AuxiliaryMethods::stringToDouble(xmlManager.GetData()));
                expenses.push_back(expense);
            }
            xmlManager.OutOfElem();
            lastExpenseId++;
        }
    }

    return expenses;

}

bool ExpensesFile::addExpenseToFile(Expense expense){

    xmlManager.Load(getFileName());
    if (!xmlManager.FindElem("EXPENSES")) {

        xmlManager.AddElem("EXPENSES");
    }

        xmlManager.FindElem("EXPENSES");
        xmlManager.IntoElem();
        xmlManager.AddElem("EXPENSE");
        xmlManager.IntoElem();
        xmlManager.AddElem( "userId", expense.getExpenseId() );
        xmlManager.AddElem( "expenseId", expense.getUserId() );
        xmlManager.AddElem( "date", expense.getDate() );
        xmlManager.AddElem( "item", expense.getItem() );
        xmlManager.AddElem( "amount", AuxiliaryMethods::doubleToString(expense.getAmount()) );

        lastExpenseId++;

        if(xmlManager.Save(getFileName())){
            return true;
        } else {
            return false;
        }
}
