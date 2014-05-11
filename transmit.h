#ifndef TRANSMIT_H
#define TRANSMIT_H
#include <QDateTime>
#include <QTimer>
#include <ctime>
#include "enheder.h"
#include "totalkonfiguration.h"
#include <QDebug>

class transmit
{
public:
    transmit();
    void changelamp(bool, int, bool);
    int checkcalender(enheder*, totalkonfiguration*);

private:

QDate date;

};

#endif // TRANSMIT_H
