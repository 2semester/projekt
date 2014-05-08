#include "lysenhed.h"

lysenhed::lysenhed()
{
}
QString lysenhed::getname(){
    return lysenhed::name;
}

QString lysenhed::getdesc(){
    return lysenhed::desc;
}

int lysenhed::gettype(){
    return lysenhed::type;
}

int lysenhed::getID(){
    return lysenhed::ID;
}

bool lysenhed::getstatus(){
    return lysenhed::status;
}

void lysenhed::setname(QString newname){
    lysenhed::name = newname;
    return;
}

void lysenhed::setdesc(QString newdesc){
    lysenhed::desc = newdesc;
    return;
}

void lysenhed::settype(int newtype){
    lysenhed::type = newtype;
    return;
}

void lysenhed::setID(int newID){
    lysenhed::ID = newID;
    return;
}

void lysenhed::setstatus(bool newstatus){
    lysenhed::status = newstatus;
    return;
}
