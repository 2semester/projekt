#ifndef EDITUNITS_H
#define EDITUNITS_H

#include <QDialog>
#include "enheder.h"

namespace Ui {
class editunits;
}

class editunits : public QDialog
{
    Q_OBJECT

public:
    explicit editunits(QWidget *parent = 0);
    ~editunits();
    void giveptr(enheder*);
private slots:


    void on_Add_clicked();

    void on_remove_clicked();

    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::editunits *ui;
    QStringList tableHeader;
    int type, ID;
    QString name, desc;
    enheder *ptrenheder;
};

#endif // EDITUNITS_H
