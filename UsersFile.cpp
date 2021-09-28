#include "UsersFile.h"
#include <vector>
#include "AuxiliaryMethods.h"


bool UsersFile::addUserToFile(User user){

     //if (!isFileExists()){
     //   xmlManager.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    // }

       xmlManager.Load(getFileName());

       if (!xmlManager.FindElem("USERS")) {
          xmlManager.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
          xmlManager.AddElem("USERS");
        }

        xmlManager.FindElem("USERS");
        xmlManager.IntoElem();
        xmlManager.AddElem("USER");
        xmlManager.IntoElem();
        xmlManager.AddElem( "userId", user.getUserId() );
        xmlManager.AddElem( "login", user.getLogin() );
        xmlManager.AddElem( "password", user.getPassword() );
        xmlManager.AddElem( "name", user.getName() );
        xmlManager.AddElem( "surname", user.getSurname() );

        if(xmlManager.Save(getFileName())){
            return true;
        } else {
            return false;
        }
}

vector<User> UsersFile::getUsersFromFile(){

    User user;
    vector<User> users;

    if (isFileExists())
    {
        xmlManager.Load(getFileName());
        xmlManager.FindElem("USERS");
        xmlManager.IntoElem();

        while ( xmlManager.FindElem("USER") )
        {

            xmlManager.IntoElem();
            xmlManager.FindElem( "userId" );
            user.setUserId(atoi(xmlManager.GetData().c_str()));
            xmlManager.FindElem( "login" );
            user.setLogin(xmlManager.GetData());
            xmlManager.FindElem( "password" );
            user.setPassword(xmlManager.GetData());
            xmlManager.FindElem( "name" );
            user.setName(xmlManager.GetData());
            xmlManager.FindElem( "surname" );
            user.setSurname(xmlManager.GetData());
            xmlManager.OutOfElem();
            users.push_back(user);
        }
        return users;
    }
    else return users;
}


void UsersFile::saveNewPasswordToFile(string newPassword, int loggedUserId){

    xmlManager.ResetPos();
    if (isFileExists()) {

        xmlManager.FindElem();
        xmlManager.IntoElem();
        while (xmlManager.FindElem("USER")) {

            xmlManager.FindChildElem("userId");
            if (xmlManager.GetChildData() == AuxiliaryMethods::intToString(loggedUserId)) {

                xmlManager.FindChildElem("password");
                xmlManager.SetChildData(newPassword);
            }
        }
    }
    xmlManager.Save(getFileName());

}
