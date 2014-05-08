#ifndef NEWLIGHTINFO_H
#define NEWLIGHTINFO_H

#include <QDialog>

namespace Ui {
class newlightinfo;
}

class newlightinfo : public QDialog
{
    Q_OBJECT

public:
    explicit newlightinfo(QWidget *parent = 0);
    ~newlightinfo();

    QString returnName();
    QString returnDesc();
    int returnType();
    int returnID();
    bool valid;
    QString name, desc;
    int type, ID;
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::newlightinfo *ui;
};

#endif // NEWLIGHTINFO_H
