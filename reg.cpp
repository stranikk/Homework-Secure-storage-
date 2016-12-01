#include "reg.h"
#include "database.h"
#include "ui_reg.h"
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QCryptographicHash>
Reg::Reg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reg)
{
    ui->setupUi(this);
    id=0;
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
    QString pas=ui->lineEdit_2->text();
    QString rpas=ui->lineEdit_3->text();
    QString fname=ui->lineEdit_4->text();
    QString lname=ui->lineEdit_5->text();
    QByteArray ba=pas.toUtf8();

    if(pas==rpas){
        id=id+1;
        db->insertIntoTable(id,fname,lname,log,QCryptographicHash::hash(ba,QCryptographicHash::Sha256).toHex());
        this->hide();
    }
    else{
    ui->label_7->setText("Check password");
    }

}


