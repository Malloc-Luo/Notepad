#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QTimer>
#include <QDebug>
#include <QFileSystemWatcher>
#include "findwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void newFile();

    void saveFile();

    void saveAll();

    void saveAs();

    void openFile();

    void setBold(bool );

    void setUnderline(bool );

    void setItalic(bool );

    void findtext();
    
private slots:
    void on_actionOpen_O_triggered();   //open file

    void on_actiontuichu_triggered();   //exit

    void on_actionNew_N_triggered();    //new file

    void on_actionSave_S_triggered();   //save file

    void on_action_lingcvunwei_triggered(); //save file as
    
    void isChanged(bool changed);   //if text modified

    void on_actionItalic_triggered(bool checked);     //set text font to Italic

    void on_actionBold_triggered(bool checked);

    void on_actionUnderline_triggered(bool checked);

    void on_actionAbout_Notepad_2_triggered();  //about

    void on_actionFind_triggered();     //find

    void on_actionHelp_triggered();     //help

    void findintext(const QString & exp, unsigned char rule); //find

private:
    bool isUntitle;

    bool isModified;

    QString path;

    QString tempPath;

    FindWindow * wfind;

    //[0]->(isUntitle) [1]->(isModified) [2]->(isCallSetModified)...
    unsigned char status;

    QTimer * timer;
    
    QFileSystemWatcher * filewatcher;

protected:

    void closeEvent(QCloseEvent * event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
