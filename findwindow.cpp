#include "findwindow.h"
#include "mainwindow.h"
#include "ui_findwindow.h"

FindWindow::FindWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon/icon/find"));
    this->setWindowTitle(tr("查找"));
    this->setFixedSize(this->width(), this->height());
    this->FindRule.rule = (QTextDocument::FindFlag)0;
    this->FindRule.isCaseSenstive = (QTextDocument::FindFlag)0;
    this->FindRule.isforward = (QTextDocument::FindFlag)0;
    this->FindRule.isWholeWords = (QTextDocument::FindFlag)0;

    this->findRule = 0;

    ui->Findnext->setEnabled(false);
}

FindWindow::~FindWindow()
{
    qDebug() << "wfind is deleted";
    delete ui;
}

void FindWindow::on_pushButton_2_clicked()
{
    accept();
}

void FindWindow::on_Case_clicked(bool checked)
{
//    this->FindRule.isCaseSenstive = checked ? QTextDocument::FindCaseSensitively : (QTextDocument::FindFlag)0;
    this->findRule = checked ? this->findRule | 0x04 : this->findRule & 0xfb;
}

void FindWindow::on_WholeWords_clicked(bool checked)
{
//    this->FindRule.isWholeWords = checked ? QTextDocument::FindWholeWords : (QTextDocument::FindFlag)0;
    this->findRule = checked ? this->findRule | 0x02 : this->findRule & 0xfd;
}

void FindWindow::on_forward_toggled(bool checked)
{
//    this->FindRule.isforward = !checked ? QTextDocument::FindBackward : (QTextDocument::FindFlag)0;
    this->findRule = !checked ? this->findRule | 0x01 : this->findRule & 0xfe;
}

void FindWindow::on_Findnext_clicked()
{
//    emit this->Send_findInfo(this->keyword, this->FindRule.isCaseSenstive | this->FindRule.isforward | this->FindRule.isWholeWords);
    emit this->Send_findInfo(this->keyword, this->findRule);
}

void FindWindow::on_lineEdit_textChanged(const QString &arg1)
{
    this->keyword = arg1;
    if(this->keyword.isEmpty())
    {
        this->ui->Findnext->setEnabled(false);
    }
    else
    {
        this->ui->Findnext->setEnabled(true);
    }
}
