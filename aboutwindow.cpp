#include "aboutwindow.h"
#include "ui_aboutwindow.h"
#include <QDesktopServices>
#include <QUrl>

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon/about"));
    this->setWindowTitle(tr("关于Notepad-=2"));
    this->setFixedSize(this->width(), this->height());
}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::on_pushButton_clicked()
{
    accept();
}

void AboutWindow::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://github.com/Malloc-Luo/Notepad")));
}
