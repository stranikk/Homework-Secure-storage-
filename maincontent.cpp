#include "maincontent.h"
#include "ui_maincontent.h"

MainContent::MainContent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainContent)
{
    ui->setupUi(this);
}

MainContent::~MainContent()
{
    delete ui;
}
