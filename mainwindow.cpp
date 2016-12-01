#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reg.h"
#include "database.h"
#include "maincontent.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(on_return()), ui->pushButton, SLOT(click()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    sReg = new Reg();
    sReg->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    db = new DataBase();
    db->show();
}

void MainWindow::on_pushButton_clicked()
{
    QString Log,Pas;

    Log=ui->lineEdit->text();
    Pas=ui->lineEdit_2->text();
    if(db->checkLogPas(Log,Pas)==true){
        pContent = new MainContent();
        pContent->show();
        pContent->setFnameLname(Log);
        this->hide();
    }
    else{
        ui->label_4->setText("Please check login or password");
    }
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    int itcoutn=arg1.length();
    QString arg2 = arg1;
    str += arg2.remove("[a-z]");

    arg2.replace(QRegularExpression("."), "*");
    //ui->lineEdit_2->setText(arg2);
}



void MainWindow::on_lineEdit_2_returnPressed()
{
    emit on_return();
}
