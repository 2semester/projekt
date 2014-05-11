#ifndef TOTALKONFIGURATION_H
#define TOTALKONFIGURATION_H

#include <vector>
#include "konfiguration.h"

class totalkonfiguration
{
public:
    totalkonfiguration();
    void nykonfiguration(konfiguration);
    konfiguration getkonfiguration(int);
    void fjernkonfiguration(int);
    std::vector<konfiguration> konfigurationliste;
private:

};

#endif // TOTALKONFIGURATION_H
