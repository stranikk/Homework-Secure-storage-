#include "database.h"
#include "ui_database.h"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QDebug>
#include <QByteArray>
#include <QCryptographicHash>

DataBase::DataBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataBase)
{
    ui->setupUi(this);
}

DataBase::~DataBase()
{
    delete ui;

}

void DataBase::on_pushButton_clicked()
{

    connectDatabase();
   //Осуществляем запрос
   QSqlQuery query;
   query.exec("SELECT id, Firstname, LastName, Login, Password FROM Registration");

   //Выводим значения из запроса
   while (query.next())
   {
   int id = query.value(0).toInt();
   QString Fname = query.value(1).toString();
   QString Lname = query.value(2).toString();
   QString Login = query.value(3).toString();
   QString Password = query.value(4).toString();
   ui->textEdit->insertPlainText(id+" "+Fname+" "+Lname+" "+Login+" "+Password+"\n");
   }
}

void DataBase::connectDatabase()
{
    //Подключаем базу данных
   QSqlDatabase db;
   db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("/Users/nikitakurganov/Documents/Qt/Data/Database.db3");
   if(!db.open()){
         qDebug() << "Не удалось восстановить базу данных";
   }
}

int DataBase::setid()
{
    int id;
    connectDatabase();
    QSqlQuery query;
    query.exec("SELECT id, Firstname, LastName, Login, Password FROM Registration");
    while (query.next()){
        id=query.value(0).toInt();
    }
    return id;
}



bool DataBase::checkLogPas(QString EntLog,QString EntPas)
{
    //int id;
    QString login,password;
    connectDatabase();
    QSqlQuery query;
    query.exec("SELECT id, Firstname, LastName, Login, Password FROM Registration");
    QByteArray ba=EntPas.toUtf8();
    while (query.next()){
        login=query.value(3).toString();
        password=query.value(4).toString();
        if ((EntLog==login)&&((QCryptographicHash::hash(ba,QCryptographicHash::Sha256).toHex())==password)){
            return true;
        }
        else {
            return false;
        }
    }

}

QString DataBase::getFname(QString log)
{
    QString login,Fname;
    connectDatabase();
    QSqlQuery query;
    query.exec("SELECT id, Firstname, LastName, Login, Password FROM Registration");
    while (query.next()){
        login=query.value(3).toString();
        Fname=query.value(1).toString();
        if (log==login){
            return Fname;
        }

    }
}

QString DataBase::getLname(QString log)
{
    QString login,Lname;
    connectDatabase();
    QSqlQuery query;
    query.exec("SELECT id, Firstname, LastName, Login, Password FROM Registration");
    while (query.next()){
        login=query.value(3).toString();
        Lname=query.value(2).toString();
        if (log==login){
            return Lname;
        }

    }
}
void DataBase::insertIntoTable(int id, QString Fname, QString LName, QString Login, QString Password)
{
    connectDatabase();
    QSqlQuery query;
    query.prepare("INSERT INTO Registration (id,FirstName,LastName,Login,Password)"
                  "VALUES(?,?,?,?,?)");
    query.addBindValue(id);
    query.addBindValue(Fname);
    query.addBindValue(LName);
    query.addBindValue(Login);
    query.addBindValue(Password);
    query.exec();
}
