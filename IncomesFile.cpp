#include "IncomesFile.h"


int IncomesFile::getLastIncomeId(){

 return lastIncomeId;
}

vector<Income> IncomesFile::loadLoggedUserIncomesFromFile(int loggedUserId){

Income income;
vector<Income> incomes;

    string dane = "";
    xmlManager.Load(getFileName());
    xmlManager.ResetPos();

    if (isFileExists()) {

        xmlManager.FindElem("INCOMES");
        xmlManager.IntoElem();

        while (xmlManager.FindElem("INCOME")) {

            xmlManager.IntoElem();
            xmlManager.FindElem("userId");

            if (AuxiliaryMethods::stringToInt(xmlManager.GetData()) == loggedUserId) {

                income.setUserId(loggedUserId);
                xmlManager.FindElem("incomeId");
                income.setIncomeId(AuxiliaryMethods::stringToInt(xmlManager.GetData()));
                xmlManager.FindElem("date");
                income.setDate(xmlManager.GetData());
                xmlManager.FindElem("item");
                income.setItem(xmlManager.GetData());
                xmlManager.FindElem("amount");
                income.setAmount(AuxiliaryMethods::stringToDouble(xmlManager.GetData()));
                incomes.push_back(income);
            }
            xmlManager.OutOfElem();
            lastIncomeId++;
        }
    }

    return incomes;

}

bool IncomesFile::addIncomeToFile(Income income){

    xmlManager.Load(getFileName());
    if (!xmlManager.FindElem("INCOMES")) {

        xmlManager.AddElem("INCOMES");
    }

        xmlManager.FindElem("INCOMES");
        xmlManager.IntoElem();
        xmlManager.AddElem("INCOME");
        xmlManager.IntoElem();
        xmlManager.AddElem( "userId", income.getUserId() );
        xmlManager.AddElem( "incomeId", income.getIncomeId() );
        xmlManager.AddElem( "date", income.getDate() );
        xmlManager.AddElem( "item", income.getItem() );
        xmlManager.AddElem( "amount", AuxiliaryMethods::doubleToString(income.getAmount()) );

        lastIncomeId++;

        if(xmlManager.Save(getFileName())){
            return true;
        } else {
            return false;
        }
}
