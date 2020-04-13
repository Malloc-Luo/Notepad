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


void MainWindow::ini_init()
{
    if(QFileInfo::exists("user.ini"))
    {
        this->ini = new QSettings("user.ini", QSettings::IniFormat);

        this->ui->textEdit->setFont(QFont(this->ini->value("/Font/fontfamily").toString()));

        this->ui->textEdit->setFontPointSize(qreal(this->ini->value("/Font/fontsize").toInt()));

        this->ui->textEdit->setTextColor(QColor(this->ini->value("/Font/color").toString()));

        this->tempPath = this->ini->value("/Path/path").toString();

        delete this->ini;
    }
    else
    {
        this->ini = new QSettings("user.ini", QSettings::IniFormat);
        ini->setValue("/user/first", 0);
        delete this->ini;
    }
}


void MainWindow::change_ini()
{
    this->ini = new QSettings("user.ini", QSettings::IniFormat);

    ini->setValue("Font/fontfamily", this->ui->textEdit->font());

    ini->setValue("Font/fontsize", this->ui->textEdit->fontPointSize());

    ini->setValue("Font/color", this->ui->textEdit->textColor());

    ini->setValue("Path/path", this->path);

    delete this->ini;
}




















