#ifndef LYSENHED_H
#define LYSENHED_H

#include <QDialog>

class lysenhed
{
public:
    lysenhed();
    QString getname();
    QString getdesc();
    int gettype();
    int getID();
    bool getstatus();
    void setname(QString);
    void setdesc(QString);
    void settype(int);
    void setID(int);
    void setstatus(bool);

private:
    QString name, desc;
    int type, ID;
    bool status;
};

#endif // LYSENHED_H
