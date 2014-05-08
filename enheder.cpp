#include "enheder.h"

enheder::enheder()
{
}

void enheder::nyenhed(lysenhed nyenhed){
    enheder::lysenheder.push_back(nyenhed);
    return;
}

lysenhed enheder::getenhed(int i){
     return enheder::lysenheder.at(i);
}

void enheder::fjernenhed(int i){
    enheder::lysenheder.erase(enheder::lysenheder.begin() + i);
    return;
}

