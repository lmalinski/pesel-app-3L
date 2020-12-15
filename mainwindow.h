#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Program;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,
               Program *app = nullptr);
    ~MainWindow();

private slots:
    void on_pesel_editingFinished();
    void on_verifyBut_clicked();
    void on_verifyOK();
    void on_verifyFAIL(const QString);
    void on_showResults(int,QDate,QString);

    void on_processBut_clicked();

private:
    Ui::MainWindow *ui = nullptr;
    Program *mainApp = nullptr;
};
#endif // MAINWINDOW_H
