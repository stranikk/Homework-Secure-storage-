#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QDialog>
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

public slots:
    void on_pushButton_3_clicked();
    void setFnameLname(QString log);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainContent *ui;
    DataBase *db;
    Crypt *cr;

};

#endif // MAINCONTENT_H
