#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QFont>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->timer = new QTimer;
    this->filewatcher = new QFileSystemWatcher;
    this->isUntitle = true;
    this->isModified = false;

    this->status = ((true << 0) | (false << 1) | (false << 2));

    this->path = tr("Untitled.txt");
    this->tempPath = tr("C:/Users");

    this->setWindowTitle(tr("Notepad-=2"));
    this->setWindowIcon(QIcon(":/icon/MAIN"));

    this->filewatcher->addPath(this->path);
    this->timer->start(600);
//    connect(timer, &QTimer::timeout, this, &MainWindow::timerout);
//    connect(filewatcher, &QFileSystemWatcher::fileChanged, this, &MainWindow::isChanged);
    connect(ui->textEdit->document(), SIGNAL(modificationChanged(bool)), SLOT(isChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete filewatcher;
}



/////////////////////////////////////////////////////////////////////////////////////
/// \brief slot functions
/////////////////////////////////////////////////////////////////////////////////////

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
        QMessageBox::StandardButton btn = QMessageBox::warning(this, tr("Notepad-=2"), tr("The file has been changed, save or not?").arg(this->path), QMessageBox::Yes | QMessageBox::Cancel | QMessageBox::No, QMessageBox::Yes);

        if(btn == QMessageBox::Cancel)
        {
            event->ignore();
        }
        if(btn == QMessageBox::Yes)
        {
            this->saveFile();
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

void MainWindow::isChanged()
{
    if(!((this->status >> 2) & 0x01))
    {
        static unsigned i = 0;
        this->setWindowTitle(this->path + tr("*"));
        this->isModified = true;
        this->status &= 0xfb;
        qDebug() << i++ ;
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
