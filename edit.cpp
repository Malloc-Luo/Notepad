#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFont>
#include <QPalette>

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

void MainWindow::findtext()
{
    this->wfind = new FindWindow;

    connect(this->wfind, &FindWindow::Send_findInfo, this, &MainWindow::findintext);

    wfind->show();
}

void MainWindow::findintext(const QString & exp, unsigned char rule)
{
    if(rule == 0)
    {
        if(!this->ui->textEdit->find(exp, QTextDocument::FindBackward))
        {
            QMessageBox::information(this, tr("查找"), tr("已查找全部：") + exp, QMessageBox::Ok, QMessageBox::Ok);
            wfind->raise();
        }
        else
        {
            QPalette palette = ui->textEdit->palette();
            palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
            ui->textEdit->setPalette(palette);
        }
    }
}
