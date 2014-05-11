#ifndef MANUALLIGHT_H
#define MANUALLIGHT_H

#include <QDialog>
#include <QLabel>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include "enheder.h"

namespace Ui {
class ManualLight;
}

class ManualLight : public QDialog
{
    Q_OBJECT

public:
    explicit ManualLight(QWidget *parent = 0);
    ~ManualLight();
    void giveptr(enheder*);
    void redraw();

private slots:
    void ok();
    void fail();

private:
    Ui::ManualLight *ui;
    QLabel *lamplabel[14];
    QLabel *label[14];
    QCheckBox *checkbox[14];
    QHBoxLayout *layout[14];
    QVBoxLayout *Vlayout;
    enheder *ptrenheder;

};

#endif // MANUALLIGHT_H
