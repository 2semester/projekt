#include "totalkonfiguration.h"

totalkonfiguration::totalkonfiguration()
{
}

void totalkonfiguration::nykonfiguration(konfiguration nykonfig){
    totalkonfiguration::konfigurationliste.push_back(nykonfig);
    return;
}

konfiguration totalkonfiguration::getkonfiguration(int i){
    return totalkonfiguration::konfigurationliste.at(i);
}

void totalkonfiguration::fjernkonfiguration(int i){
    totalkonfiguration::konfigurationliste.erase(totalkonfiguration::konfigurationliste.begin() + i);
    return;
}
