#include "login.h"

login::login()
{

}
bool login::LOGIN(QString username , QString password)
{
    QSqlQuery qry;
    qry.prepare("SELECT username, password, Role FROM USERS WHERE Username=\'"+ username +"\' AND password=\'" + password + "\'");
    qry.addBindValue(username);
    qry.addBindValue(password);
    if(qry.exec())
        if(qry.next())
            {
                QString user = QVariant(qry.value(0)).toString();
            if(user==username)
            {return true;}            }
    return false;
}

