#ifndef EDITUNITS_H
#define EDITUNITS_H

#include <QDialog>

namespace Ui {
class editunits;
}

class editunits : public QDialog
{
    Q_OBJECT

public:
    explicit editunits(QWidget *parent = 0);
    ~editunits();

private slots:


    void on_Add_clicked();

    void on_remove_clicked();

    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::editunits *ui;
    QStringList tableHeader;
    int type, room;
    QString name, desc;
};

#endif // EDITUNITS_H
