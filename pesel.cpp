#include "pesel.h"

Pesel::Pesel(QString pesel)
    : m_pesel(pesel)
{}

void Pesel::decompose()
{
    if(m_isDecomposed == false)
    for(size_t i=0;i < PESEL_LENGTH;i++)
    {
        char digit = m_pesel.at(i).toLatin1();
        m_digits[i] = digit - '0';
    }
    m_isDecomposed = true;
}

bool Pesel::verifyNumChar()
{
    return m_pesel.length() == PESEL_LENGTH;
}

bool Pesel::verifyDigits()
{
    for(QChar ch : m_pesel)
        if(!ch.isDigit())
            return false;
    return true;
}

bool Pesel::verifyCtrSum()
{
    decompose();
    short const weights[] = {1,3,7,9,1,3,7,9,1,3,1};
    int suma = 0;
    for( size_t i =0;i<PESEL_LENGTH;i++)
        suma+=m_digits[i]*weights[i];
    return (suma%10==0);
}

QString Pesel::getGender()
{
    decompose();
    if(m_digits[9] % 2) return "Mężczyzna";
    else return "Kobieta";
}


QDate Pesel::getBirthDate()
{
    int encodedMonth = 10*m_digits[2]+m_digits[3];
    int milenium = 1900,realMonth = encodedMonth;
    const int milenia[] = {1800,2200,2100,2000};
    const int offsets[] = {80,60,40,20};
    const int NUM_OFF = sizeof(offsets)/sizeof(int);
    for(int i = 0; i<NUM_OFF; i++)
    {
        if(offsets[i]< encodedMonth)
        {
            milenium = milenia[i];
            realMonth = encodedMonth-offsets[i];
            break;
        }
    }
    int year = milenium + 10*m_digits[0]+m_digits[1];
    int day = 10*m_digits[4]+m_digits[5];
    return QDate(year,realMonth,day);
}
int Pesel::getAge()
{
    return (QDate::currentDate().year() - getBirthDate().year());
}
