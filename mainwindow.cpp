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
        this->hide();
    }
    else{
        ui->label_4->setText("Please check login or password");
    }
}
