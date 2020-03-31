#ifndef FINDWINDOW_H
#define FINDWINDOW_H

#include <QDialog>
#include <QTextDocument>


namespace Ui {
class FindWindow;
}

class FindWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FindWindow(QWidget *parent = 0);
    ~FindWindow();

public:
    void findNext();

signals:
//    void Send_findInfo(const QString &exp, QTextDocument::FindFlags rule);
    void Send_findInfo(const QString & exp, unsigned char rule);

private slots:
    void on_pushButton_2_clicked();

    void on_Case_clicked(bool checked);

    void on_WholeWords_clicked(bool checked);

    void on_forward_toggled(bool checked);

    void on_Findnext_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    QString keyword;

    struct findrule
    {
        QTextDocument::FindFlag isforward;
        QTextDocument::FindFlag isCaseSenstive;
        QTextDocument::FindFlag isWholeWords;
        QTextDocument::FindFlag rule;
    }FindRule;

    unsigned char findRule;

private:
    Ui::FindWindow *ui;
};

#endif // FINDWINDOW_H
