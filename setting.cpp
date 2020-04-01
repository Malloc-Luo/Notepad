#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>
#include <QColor>


void MainWindow::setBold(bool selected)
{
    QFont font = this->ui->textEdit->font();
    font.setBold(selected);
    this->ui->textEdit->setFont(font);
}

void MainWindow::setUnderline(bool selected)
{
    QFont font = this->ui->textEdit->font();
    font.setUnderline(selected);
    this->ui->textEdit->setFont(font);
}

void MainWindow::setItalic(bool selected)
{
    QFont font = this->ui->textEdit->font();
    font.setItalic(selected);
    this->ui->textEdit->setFont(font);
}


void MainWindow::setFont()
{
/*
    QFontDialog * wfont = new QFontDialog(QFont("Courier new", 11), this);
    wfont->setWindowIcon(QIcon(":/icon/font"));
    wfont->setWindowTitle(tr("字体选择"));
    QFont font = wfont->selectedFont();

    if(wfont->exec() == QDialog::Accepted)
    {
        this->ui->textEdit->setFont(font);
    }

    delete wfont;
*/
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Courier new", 11), this, tr("选择字体"));
    if(ok)
    {
        this->ui->textEdit->setFont(font);
    }
    else
    {
        return;
    }
}

void MainWindow::setFontColor()
{
//    bool ok;
    QColor color = QColorDialog::getColor(Qt::black, this, tr("选择颜色"));
    this->ui->textEdit->setTextColor(color);
}
