#ifndef CONTROLLIGHT_H
#define CONTROLLIGHT_H

#include <QDialog>
#include "totalkonfiguration.h"
#include "enheder.h"

namespace Ui {
class controllight;
}

class controllight : public QDialog
{
    Q_OBJECT

public:
    explicit controllight(QWidget *parent = 0);
    ~controllight();
    void giveptr(enheder*, totalkonfiguration*);

private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

    void on_on_clicked();

    void on_off_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::controllight *ui;
    QStringList tableHeader;
};

#endif // CONTROLLIGHT_H
