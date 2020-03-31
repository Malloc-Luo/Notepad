#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFont>

void MainWindow::setBold(bool selected)
{
    QFont font = this->ui->textEdit->font();
    font.setBold(selected);
    this->ui->textEdit->setFont(font);
}

void MainWindow::setUnderline(bool selected)
{
    bool isUnderline = this->ui->textEdit->fontUnderline();
    this->ui->textEdit->setFontUnderline(!isUnderline);
}

void MainWindow::setItalic(bool selected)
{
    bool isItalic = this->ui->textEdit->fontItalic();
    this->ui->textEdit->setFontItalic(!isItalic);
}
