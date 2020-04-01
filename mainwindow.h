#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QTimer>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QTextCursor>
#include "findwindow.h"
#include <QDialog>
#include <QFontDialog>
#include <QColorDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString Title = tr("Notepadm2");

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void newFile();

    bool saveFile();    //save successfully ? true : false

    void saveAll();

    void saveAs();

    void openFile();

    void setBold(bool );

    void setUnderline(bool );

    void setItalic(bool );

    void setFont();

    void setFontColor();

    void findtext();

    void autoCheckLine(bool );

    void edit_init();
    
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

    void on_actioncheckline_triggered(bool checked);

    void on_actionUndo_U_triggered();

    void get_cursor();

    void on_actionfont_2_triggered();

    void on_actioncolor_triggered();

signals:
    void Send_cursor_position(int b, int c);

public slots:
    void Show_cursor_position(int b, int c);

private:
    bool isUntitle;

    bool isModified;

    QTextCursor Cursor;

    QString path;

    QString tempPath;

    QTimer * timer;
    
    QFileSystemWatcher * filewatcher;

    FindWindow * wfind;

private:
    bool findwindowCreated;

protected:

    void closeEvent(QCloseEvent * event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
