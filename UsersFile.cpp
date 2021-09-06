#include "UsersFile.h"
#include <vector>

void UsersFile::addUserToFile(User user){

    xmlManager.Load(getFileName());
    if (!xmlManager.FindElem("USERS")) {

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
        xmlManager.Save(getFileName());
}

vector<User> UsersFile::getUsersFromFile(){

    User user;
    vector<User> users;

    if (ifFileExists())
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
