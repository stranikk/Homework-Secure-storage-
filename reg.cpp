#include "reg.h"
#include "database.h"
#include "ui_reg.h"

Reg::Reg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reg)
{
    ui->setupUi(this);

}

Reg::~Reg()
{
    delete db;
    delete ui;
}



void Reg::on_pushButton_clicked()
{
    db->connectDatabase();
    QString log=ui->lineEdit->text();
    //QString pas=ui->lineEdit_2->text();
    //QString rpas=ui->lineEdit_3->text();
    QString fname=ui->lineEdit_4->text();
    QString lname=ui->lineEdit_5->text();
    QByteArray ba=str.toUtf8();
    if((db->checkLogin(log))==true){
        ui->label_8->setText("This login at used");
    }
    else{
    if(str==str1){
        qDebug()<<"FPas: "<<str<<"LPas: "<<str1;
        db->insertIntoTable(fname,lname,log,QCryptographicHash::hash(ba,QCryptographicHash::Sha256).toHex());
        this->hide();
    }
    else{
    ui->label_7->setText("Check password");
    }
    }

}



void Reg::on_lineEdit_2_textChanged(const QString &arg1)
{
    if(sTextchanged){
        int itcoutn=arg1.length();
        QString arg2 = arg1;
        QString arg3 = arg1;
        if(str.size() == itcoutn+1){
            str.resize(str.size()-1);
        }
        else str += arg2.remove("*");

        arg3.replace(QRegularExpression("."), "*");
        sTextchanged = false;
        ui->lineEdit_2->setText(arg3);
    }
    sTextchanged = true;
}

void Reg::on_lineEdit_3_textChanged(const QString &arg1)
{
    if(sTextchanged1){
        int itcoutn=arg1.length();
        QString arg2 = arg1;
        QString arg3 = arg1;
        if(str1.size() == itcoutn+1){
            str1.resize(str1.size()-1);
        }
        else str1 += arg2.remove("*");

        arg3.replace(QRegularExpression("."), "*");
        sTextchanged1 = false;
        ui->lineEdit_3->setText(arg3);
    }
    sTextchanged1 = true;
}
