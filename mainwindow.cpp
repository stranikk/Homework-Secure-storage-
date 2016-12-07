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
    pContent = new MainContent();
    sReg = new Reg();
    db = new DataBase();

    connect(pContent, &MainContent::firstWindow, this, &MainWindow::show);
    connect(sReg, &Reg::firstWindow, this, &Reg::show);
    connect(this, SIGNAL(on_return()), ui->pushButton, SLOT(click()));
    //строки и так пустые
    //log.clear();
    //str.clear();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete pContent;
    //можно выйти из программы не нажав кнопку 3
    delete db;
    delete sReg;
}

void MainWindow::on_pushButton_2_clicked()
{
    sReg->show();
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    db->show();
}

void MainWindow::on_pushButton_clicked()
{
    QString Log;

    Log=ui->lineEdit->text();

    if(db->checkLogPas(Log,str)==true){
        log=Log;
        pContent->setLogPas(log,str);
        pContent->show();
        pContent->setFnameLname(Log);
        this->close();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();

    }
    else{
        ui->label_4->setText("Please check login or password");
    }
    log.clear();
    str.clear();

}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
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



void MainWindow::on_lineEdit_2_returnPressed()
{
    emit on_return();
}
