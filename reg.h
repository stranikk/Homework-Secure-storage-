#ifndef REG_H
#define REG_H

#include <QDialog>
#include "database.h"
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

private:
    Ui::Reg *ui;
    DataBase *db;
    int id;

};

#endif // REG_H
