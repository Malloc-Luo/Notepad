#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QTimer>
#include <QDebug>
#include <QFileSystemWatcher>

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
    
private slots:
    void on_actionOpen_O_triggered();

    void on_actiontuichu_triggered();

    void on_actionNew_N_triggered();

    void on_actionSave_S_triggered();

    void on_action_lingcvunwei_triggered();
    
    void isChanged();

    void on_actionItalic_triggered(bool checked);

    void on_actionBold_triggered(bool checked);

    void on_actionUnderline_triggered(bool checked);

private:
    bool isUntitle;
    bool isModified;
    QString path;
    QString tempPath;

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
