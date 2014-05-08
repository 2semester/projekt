#ifndef KONFIGURATION_H
#define KONFIGURATION_H

#include <QDialog>

class konfiguration
{
public:
    konfiguration();
    bool getstatus(int, int);
    void setstatus(int, int, bool);
    QString getdesc();
    void setdesc(QString);
private:
    bool plan[24][7];
    QString desc;
};

#endif // KONFIGURATION_H
