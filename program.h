#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include <QDate>
#include "pesel.h"

class MainWindow;

enum class Sex{male,female};

class Program : public QObject
{
    Q_OBJECT
public:
    explicit Program(QObject *parent = nullptr);
    void setGUI(MainWindow *ui = nullptr) {GUI = ui;}
    void verifyData(const QString &pesel);
    void processData(const QString &pesel);
signals:
    void verifyOK();
    void verifyFAIL(const QString);
    void showResults(int,QDate,QString);

private:
    MainWindow *GUI= nullptr;
};

#endif // PROGRAM_H
