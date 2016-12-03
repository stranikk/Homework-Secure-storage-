#ifndef REG_H
#define REG_H

#include <QDialog>
#include "database.h"
#include <QRegularExpression>
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QCryptographicHash>
namespace Ui {
class Reg;
}

class Reg : public QDialog
{
    Q_OBJECT

public:
    explicit Reg(QWidget *parent = 0);
    ~Reg();



private slots:
    void on_pushButton_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

private:
    Ui::Reg *ui;
    DataBase *db;
    QString str;
    QString str1;
    bool sTextchanged = true;
    bool sTextchanged1 = true;
};

#endif // REG_H
