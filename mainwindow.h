#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include "reg.h"
#include "database.h"
#include "maincontent.h"
#include <QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void on_return();
private slots:
    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);



    void on_lineEdit_2_returnPressed();

private:
    Ui::MainWindow *ui;
    Reg *sReg;
    DataBase *db;
    MainContent *pContent;
    QString str;
    bool sTextchanged = true;

};

#endif // MAINWINDOW_H
