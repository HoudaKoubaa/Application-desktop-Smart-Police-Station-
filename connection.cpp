#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source");//inserer le nom de la source de données ODBC
    db.setUserName("dadou");//inserer nom de l'utilisateur
    db.setPassword("esprit2000");//inserer mot de passe de cet utilisateur

    if (db.open())
    test=true;




    return  test;
}
