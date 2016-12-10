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
    delete cr;
}

void MainContent::on_pushButton_3_clicked()
{
    ui->textEdit->clear();
    this->close();
    emit firstWindow();
}

void MainContent::setFnameLname(QString log)
{
    ui->label_3->setText(db->getFname(log));
    ui->label_4->setText(db->getLname(log));
    ui->label_6->setText(log);
}

void MainContent::setLogPas(QString log, QString pas)
{
    mainLog=log;
    mainPas=pas;
}




void MainContent::on_pushButton_clicked()
{
    QString text;
    text=ui->lineEdit->text();

    std::string stdstr= cr->myCrypt(text.toStdString(),logToKey(getLog()).toStdString(),pasToKey(getPas()).toStdString(),true);

    QString str(stdstr.c_str());

    QString fileName=QFileDialog::getSaveFileName(this,tr("Save File"),
                                                  "/Users/nikitakurganov/Documents/Qt/Files/untitled.txt",
                                                  tr("Text files (*.txt);;All files (*.*)"));

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<str;
    ui->lineEdit->clear();

    file.close();
}

QString MainContent::logToKey(QString log)
{
    QByteArray ba=log.toUtf8();
    log=QCryptographicHash::hash(ba,QCryptographicHash::Sha256).toHex();
    log=log.mid(0,16);
    for (int i{log.size()};i < 16;++i){
       log +="e";
       log.replace(QRegularExpression("[g-zG-Z]"), "f");
    }


    return log;
}

QString MainContent::pasToKey(QString pas)
{
    QByteArray ba=pas.toUtf8();
    pas=QCryptographicHash::hash(ba,QCryptographicHash::Sha256).toHex();
    pas=pas.mid(0,16);
    for (int i{pas.size()};i < 16;++i){
       pas +="e";
       pas.replace(QRegularExpression("[g-zG-Z]"), "d");
    }


    return pas;
}

void MainContent::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/Users/nikitakurganov/Documents/Qt/Files",
                                                    tr("Text files (*.txt);;All files (*.*)"));
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QByteArray data;
    data = file.readAll();

    try{
        if(!QString(data).isEmpty()){
            std::string stdstr=cr->myCrypt(QString(data).toStdString(),logToKey(getLog()).toStdString(),pasToKey(getPas()).toStdString(),false);
            QString str1(stdstr.c_str());
            ui->textEdit->insertPlainText(str1);
        }
    }
    catch(const std::exception &ex){
                qDebug() << QString(ex.what());
                ui->textEdit->insertPlainText("Error with decode!!!");
            }
            catch(...){
                qDebug() << "error with decode";
            }

    file.close();

}

QString MainContent::getLog()
{
    return mainLog;
}

QString MainContent::getPas()
{
    return mainPas;
}

void MainContent::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/Users/nikitakurganov/Documents/Qt/Files",
                                                    tr("Text files (*.txt);;All files (*.*)"));
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QByteArray data;
    data = file.readAll();
    file.close();
    if(!QString(data).isEmpty()){
        std::string stdstr=cr->myCrypt(QString(data).toStdString(),logToKey(getLog()).toStdString(),pasToKey(getPas()).toStdString(),true);
        QString str1(stdstr.c_str());
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out<<str1;
        file.close();
    }

}
