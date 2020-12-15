#include "program.h"
#include "mainwindow.h"
#include "qdebug.h"

Program::Program(QObject *parent) : QObject(parent)
{}

void Program::verifyData(const QString &pesel)
{
    Pesel num(pesel);
    if(!num.verifyNumChar())
    {
        emit verifyFAIL(QString("Za malo znaków w nr. PESEL!"));
        return;
    }
    if(!num.verifyDigits())
    {
        emit verifyFAIL(QString("Niedozwolone znaki w nr. PESEL!"));
        return;
    }
    if(!num.verifyCtrSum())
    {
        emit verifyFAIL(QString("Bład sumy kontrolnej w nr. PESEL!"));
    }
    else emit verifyOK();
}

void Program::processData(const QString &pesel )
{
    Pesel num(pesel);
    emit showResults(num.getAge(),num.getBirthDate(),num.getGender());
}


