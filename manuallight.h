#ifndef MANUALLIGHT_H
#define MANUALLIGHT_H

#include <QDialog>
#include <QLabel>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>

namespace Ui {
class ManualLight;
}

class ManualLight : public QDialog
{
    Q_OBJECT

public:
    explicit ManualLight(QWidget *parent = 0);
    ~ManualLight();

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
};

#endif // MANUALLIGHT_H
