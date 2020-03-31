#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon/help"));
    this->setWindowTitle(tr("帮助"));
    this->setFixedSize(this->width(), this->height());
}

HelpWindow::~HelpWindow()
{
    delete ui;
}

void HelpWindow::on_pushButton_clicked()
{
    accept();
}
