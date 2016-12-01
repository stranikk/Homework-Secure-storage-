#include "maincontent.h"
#include "ui_maincontent.h"
#include "mainwindow.h"
#include <QDebug>
#include <string>
MainContent::MainContent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainContent)
{
    ui->setupUi(this);
    cr = new Crypt();
}

MainContent::~MainContent()
{
    delete ui;
}

void MainContent::on_pushButton_3_clicked()
{
    this->hide();
}

void MainContent::setFnameLname(QString log)
{
    ui->label_3->setText(db->getFname(log));
    ui->label_4->setText(db->getLname(log));
    ui->label_6->setText(log);
}

void MainContent::on_pushButton_clicked()
{
    QString text;
    text=ui->lineEdit->text();

    //qDebug()<<
    std::string stdstr= cr->myCrypt(text.toStdString(),"abababababababab","babababababababa");

    QString str(stdstr.c_str());
    qDebug()<< str;


}
