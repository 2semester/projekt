#ifndef KONFIGURATION_H
#define KONFIGURATION_H

#include <QDialog>

class konfiguration
{
public:
    konfiguration();
    bool getstatus(int row, int column);
    void setstatus(int row, int column, bool status);
    QString getdesc();
    void setdesc(QString);
private:
    bool plan[24][7];
    QString desc;
};

#endif // KONFIGURATION_H
