#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QDialog>

namespace Ui {
class MainContent;
}

class MainContent : public QDialog
{
    Q_OBJECT

public:
    explicit MainContent(QWidget *parent = 0);
    ~MainContent();

private:
    Ui::MainContent *ui;
};

#endif // MAINCONTENT_H
