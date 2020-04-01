#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QFont>

///////////////////////////////////////////////////////////////////////////////////
/// \brief MainWindow::newFile  create a new file
///////////////////////////////////////////////////////////////////////////////////
void MainWindow::newFile()
{
    if(this->isModified)
    {
        QMessageBox::StandardButton btn = QMessageBox::warning(this, MainWindow::Title, tr("The file has been changed, save or not?\n") + (this->path), QMessageBox::Yes | QMessageBox::Cancel | QMessageBox::No, QMessageBox::Yes);
        if(btn == QMessageBox::Yes)
        {
            this->saveFile();
        }
        else if(btn == QMessageBox::Cancel)
        {
            return;
        }
    }

    this->ui->textEdit->clear();
    this->ui->textEdit->setVisible(true);

    this->isUntitle = true;
    this->isModified = false;

    this->ui->textEdit->document()->setModified(false);

    this->path = tr("Untitled.txt");
    this->setWindowTitle(tr("Untitled.txt"));
}


void MainWindow::openFile()
{
    QString temp = this->path;

    this->path = QFileDialog::getOpenFileName(this, tr("打开文件 - %1").arg(MainWindow::Title), this->tempPath, tr("Text Files (*.txt);;C/Cpp Files (*.c *.cpp *.h *.hpp);;python (*.py);;javascript (*.js *.json);;bat script (*.bat *.cmd)"));

    if(!this->path.isEmpty())
    {
        this->setWindowTitle(this->path);

        QFile file(this->path);

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Read File"), tr("Can't open file:\n%1").arg(this->path));
            this->path = temp;
            return;
        }

        QTextStream getin(&file);

        ui->textEdit->clear();
        ui->textEdit->setText(getin.readAll());

        file.close();
    }
    else
    {
        this->path = temp;
        return;
    }
    this->isUntitle = false;
    this->isModified = false;

    this->ui->textEdit->document()->setModified(false);

    this->tempPath = this->path;
    this->setWindowTitle(this->path);
}


bool MainWindow::saveFile()
{
    if(this->isUntitle)
    {
        this->saveAs();
    }
    else
    {
        QFile file(this->path);

        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Write File"), tr("Can't open file:\n%1").arg(this->path));
            return false;
        }
        QTextStream out(&file);
        QApplication::setOverrideCursor(Qt::WaitCursor);
        out << ui->textEdit->toPlainText();
        QApplication::restoreOverrideCursor();
        file.close();

        this->isUntitle = false;
        this->isModified = false;
        this->setWindowTitle(this->path);
    }

    this->ui->textEdit->document()->setModified(false);
    return true;
}


void MainWindow::saveAs()
{

    QString buff = this->path;

    this->path = QFileDialog::getSaveFileName(this, tr("保存文件 - %1").arg(MainWindow::Title), this->tempPath, tr("Text Files (*.txt);;C\\Cpp Files (*.c *.cpp *.h *.hpp);; python (*.py);; javascript (*.js *.json);;bat script (*.bat *.cmd)"));

    if(!this->path.isEmpty())
    {
        QFile file(this->path);

        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Write File"), tr("Can't open file:\n%1").arg(this->path));
            return;
        }

        QTextStream out(&file);

        QApplication::setOverrideCursor(Qt::WaitCursor);
        out << ui->textEdit->toPlainText();
        QApplication::restoreOverrideCursor();

        file.close();

        this->isUntitle = false;
        this->isModified = false;

        this->setWindowTitle(this->path); 
    }
    else
    {
        this->path = buff;
        return;
    }

    this->tempPath = this->path;

    this->setWindowTitle(this->path);
}























