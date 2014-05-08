#ifndef ENHEDER_H
#define ENHEDER_H
#include "lysenhed.h"
#include <vector>

class enheder
{
public:
    enheder();
    void nyenhed(lysenhed);
    lysenhed getenhed(int);
    void fjernenhed(int);
private:
    std::vector<lysenhed> lysenheder;
};

#endif // ENHEDER_H
