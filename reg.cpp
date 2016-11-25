#include "reg.h"
#include "database.h"
#include "ui_reg.h"
#include <QString>
#include <QDebug>
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
    QString pas=ui->lineEdit_2->text();
    QString rpas=ui->lineEdit_3->text();
    QString fname=ui->lineEdit_4->text();
    QString lname=ui->lineEdit_5->text();

    if(pas==rpas){
        db->insertIntoTable((db->setid())+1,fname,lname,log,pas);
        this->hide();
    }
    else{
    ui->label_7->setText("Check password");
    }

}


