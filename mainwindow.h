#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "reg.h"
#include "database.h"
#include "maincontent.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Reg *sReg;
    DataBase *db;
    MainContent *pContent;

};

#endif // MAINWINDOW_H
