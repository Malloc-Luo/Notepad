#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QFont>
#include "aboutwindow.h"
#include "helpwindow.h"
#include <QTextLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->isUntitle = true;
    this->isModified = false;
    this->findwindowCreated = false; //wfind是否被创建

    this->path = tr("Untitled.txt");
    this->tempPath = tr("C:/Users");

    this->setWindowTitle(tr("Notepad-=2"));
    this->setWindowIcon(QIcon(":/icon/MAIN2"));
//    this->timer = new QTimer;
//    this->filewatcher = new QFileSystemWatcher;
//    this->filewatcher->addPath(this->path);
//    this->timer->start(600);

    this->edit_init();

    ui->textEdit->setLineWrapMode(QTextEdit::NoWrap); //默认不换行
    connect(ui->textEdit->document(), SIGNAL(modificationChanged(bool)), SLOT(isChanged(bool)));
    connect(this, &MainWindow::Send_cursor_position, this, &MainWindow::Show_cursor_position);
}

MainWindow::~MainWindow()
{
    if(this->findwindowCreated)
        delete wfind;

    delete ui;
//    delete timer;
//    delete filewatcher;
}


void MainWindow::on_actionOpen_O_triggered()
{
    this->openFile();
}

//点击退出
void MainWindow::on_actiontuichu_triggered()
{
    close();
}

//close window
void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << this->isModified;

    if(this->isModified)
    {
        QMessageBox::StandardButton btn = QMessageBox::warning(this, tr("Notepad-=2"), tr("The file has been changed, save or not?\n") + (this->path), QMessageBox::Yes | QMessageBox::Cancel | QMessageBox::No, QMessageBox::Yes);

        if(btn == QMessageBox::Cancel)
        {
            event->ignore();
        }
        else if(btn == QMessageBox::Yes)
        {
            if(!this->saveFile())
            {
                event->ignore();
            }
        }
        else
        {
            event->accept();
        }
    }
}



void MainWindow::on_actionNew_N_triggered()
{
    this->newFile();
}

void MainWindow::on_actionSave_S_triggered()
{
    this->saveFile();
}

void MainWindow::on_action_lingcvunwei_triggered()
{
    this->saveAs();
}

void MainWindow::isChanged(bool changed)
{
    if(changed)
    {
        this->setWindowTitle(this->path + tr("*"));
        this->isModified = true;
    }
    else
    {
        this->setWindowTitle(this->path);
    }
}

void MainWindow::on_actionItalic_triggered(bool checked)
{
    this->setItalic(checked);
}

void MainWindow::on_actionBold_triggered(bool checked)
{
    this->setBold(checked);
}

void MainWindow::on_actionUnderline_triggered(bool checked)
{
    this->setUnderline(checked);
}

void MainWindow::on_actionAbout_Notepad_2_triggered()
{
    AboutWindow w;

    w.exec();
}

void MainWindow::on_actionFind_triggered()
{
    this->findwindowCreated = true;
    this->findtext();
}

void MainWindow::on_actionHelp_triggered()
{
    HelpWindow w;

    w.exec();
}

void MainWindow::on_actioncheckline_triggered(bool checked)
{
    this->autoCheckLine(checked);
}

void MainWindow::on_actionUndo_U_triggered()
{

}

void MainWindow::get_cursor()
{
    this->Cursor = ui->textEdit->textCursor();
    emit this->Send_cursor_position(this->Cursor.blockNumber(), this->Cursor.columnNumber());
}

void MainWindow::Show_cursor_position(int b, int c)
{
    this->ui->CursorP->setText(tr("行：%1 列：%2").arg(b).arg(c));
    this->ui->textEdit->setStatusTip(tr("行：%1 列：%2").arg(b).arg(c));
}













