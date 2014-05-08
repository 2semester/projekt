#include "konfiguration.h"

konfiguration::konfiguration()
{
}
bool konfiguration::getstatus(int row, int  column){
    return konfiguration::plan[row][column];
}

void konfiguration::setstatus(int row, int column, bool status){
    konfiguration::plan[row][column] = status;
    return;
}

QString konfiguration::getdesc(){
    return konfiguration::desc;
}

void konfiguration::setdesc(QString newdesc){
    konfiguration::desc = newdesc;
    return;
}
