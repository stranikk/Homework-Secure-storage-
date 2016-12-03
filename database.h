#ifndef DATABASE_H
#define DATABASE_H

#include <QWidget>

namespace Ui {
class DataBase;
}

class DataBase : public QWidget
{
    Q_OBJECT

public:
    explicit DataBase(QWidget *parent = 0);
    ~DataBase();

public slots:
    void on_pushButton_clicked();
    void connectDatabase();
    void insertIntoTable(QString Fname,QString LName,QString Login, QString Password);
    bool checkLogPas(QString EntLog,QString EntPas);
    QString getFname(QString log);
    QString getLname(QString log);
    bool checkLogin(QString log);


private:
    Ui::DataBase *ui;
};

#endif // DATABASE_H
