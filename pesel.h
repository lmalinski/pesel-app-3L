#ifndef PESEL_H
#define PESEL_H

#include <QString>
#include <QDate>

class Pesel
{
    static const int PESEL_LENGTH = 11;
    QString m_pesel  = "";
    short   m_digits[PESEL_LENGTH] = {};
    bool m_isDecomposed = false;
    void decompose();
public:
    explicit Pesel(QString pesel);
    bool verifyNumChar();
    bool verifyDigits();
    bool verifyCtrSum();
    int getAge();
    QDate getBirthDate();
    QString getGender();
};

#endif // PESEL_H
