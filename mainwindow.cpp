#include "mainwindow.h"
#include "program.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Program *app)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      mainApp(app)
{
    app->setGUI(this);
    ui->setupUi(this);

    connect(app,SIGNAL(verifyOK()),this,SLOT(on_verifyOK()));
    connect(app,SIGNAL(verifyFAIL(const QString)),
            this,SLOT(on_verifyFAIL(const QString)));
    connect(app,SIGNAL(showResults(int,QDate,QString)),
            this,SLOT(on_showResults(int,QDate,QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pesel_editingFinished()
{
    ui->processBut->setEnabled(false);
}

void MainWindow::on_verifyBut_clicked()
{
    mainApp->verifyData(ui->pesel->text());
}

void MainWindow::on_processBut_clicked()
{
   mainApp->processData(ui->pesel->text());
}

void MainWindow::on_verifyOK()
{
    ui->processBut->setEnabled(true);
}
void MainWindow::on_verifyFAIL(const QString reason)
{
    ui->statusbar->showMessage(reason);
}

void MainWindow::on_showResults(int age,
                                QDate date,
                                QString sex)
{
    ui->ageDisp->setText(QString::number(age));
    ui->dateDisp->setText(date.toString());
    ui->sexDisp->setText(sex);
}


