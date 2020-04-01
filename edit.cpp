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
    QFont font = this->ui->textEdit->font();
    font.setUnderline(selected);
    this->ui->textEdit->setFont(font);
//    bool isUnderline = this->ui->textEdit->fontUnderline();
//    this->ui->textEdit->setFontUnderline(!isUnderline);
}

void MainWindow::setItalic(bool selected)
{
    QFont font = this->ui->textEdit->font();
    font.setItalic(selected);
    this->ui->textEdit->setFont(font);
//    bool isItalic = this->ui->textEdit->fontItalic();
//    this->ui->textEdit->setFontItalic(!isItalic);
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

void MainWindow::autoCheckLine(bool checked)
{
    if(checked)
    {
        ui->textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
    }
    else
    {
        ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
    }
}

void MainWindow::edit_init()
{
    this->ui->actionUndo_U->setEnabled(false);
    this->ui->actionReundo_R->setEnabled(false);
    this->ui->actionCopy_C->setEnabled(false);

    connect(this->ui->actionclear, &QAction::triggered, this->ui->textEdit, &QTextEdit::clear);
    connect(this->ui->actionUndo_U, &QAction::triggered, this->ui->textEdit, &QTextEdit::undo);
    connect(this->ui->actionReundo_R, &QAction::triggered, this->ui->textEdit, &QTextEdit::redo);
    connect(this->ui->actionCopy_C, &QAction::triggered, this->ui->textEdit, &QTextEdit::copy);
    connect(this->ui->action_Paste_V, &QAction::triggered, this->ui->textEdit, &QTextEdit::paste);
    connect(this->ui->actionselectall, &QAction::triggered, this->ui->textEdit, &QTextEdit::selectAll);
    connect(this->ui->action_Cut_X, &QAction::triggered, this->ui->textEdit, &QTextEdit::cut);

    connect(this->ui->textEdit, &QTextEdit::undoAvailable, this->ui->actionUndo_U, &QAction::setEnabled);
    connect(this->ui->textEdit, &QTextEdit::redoAvailable, this->ui->actionReundo_R, &QAction::setEnabled);
    connect(this->ui->textEdit,&QTextEdit::copyAvailable, this->ui->actionCopy_C, &QAction::setEnabled);

    connect(this->ui->textEdit, &QTextEdit::cursorPositionChanged, this, &MainWindow::get_cursor);
}
































