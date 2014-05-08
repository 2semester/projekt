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
private:
    std::vector<konfiguration> konfigurationliste;
};

#endif // TOTALKONFIGURATION_H
