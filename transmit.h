#ifndef TRANSMIT_H
#define TRANSMIT_H
#include <QDateTime>
#include <QTimer>
#include <ctime>
#include "enheder.h"
#include "totalkonfiguration.h"
#include <QDebug>
#include "Serial.h"

class transmit
{
public:
    transmit();
    void checkcalender(enheder*, totalkonfiguration*);
    void usemanuelt(enheder*);

private:
    bool changelamp(bool, int, bool, bool);

QDate date;

};

#endif // TRANSMIT_H
