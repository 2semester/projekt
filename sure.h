#ifndef SURE_H
#define SURE_H

#include <QDialog>

namespace Ui {
class sure;
}

class sure : public QDialog
{
    Q_OBJECT

public:
    explicit sure(QWidget *parent = 0);
    ~sure();
    bool answer;

private slots:
    void on_yes_clicked();

    void on_no_clicked();

private:
    Ui::sure *ui;
};

#endif // SURE_H
