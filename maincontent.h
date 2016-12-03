#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QDialog>
#include <QRegularExpression>
#include <QDebug>
#include <QString>
#include <QCryptographicHash>
#include <QByteArray>
#include "database.h"
#include "crypt.h"

namespace Ui {
class MainContent;
}

class MainContent : public QDialog
{
    Q_OBJECT

public:
    explicit MainContent(QWidget *parent = 0);
    ~MainContent();
    void setLogPas(QString log,QString pas);
public slots:
    void on_pushButton_3_clicked();
    void setFnameLname(QString log);

private slots:
    void on_pushButton_clicked();
    QString logToKey(QString log);
    QString pasToKey(QString pas);
    void on_pushButton_2_clicked();
    QString getLog();
    QString getPas();

private:
    Ui::MainContent *ui;
    DataBase *db;
    Crypt *cr;

    QString mainLog;
    QString mainPas;
};

#endif // MAINCONTENT_H
