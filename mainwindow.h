#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "totalkonfiguration.h"
#include "enheder.h"
#include "transmit.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    totalkonfiguration c_totalkonfiguration;
    enheder c_enheder;

private slots:
    void on_button_Login_clicked();

    void on_button_editunits_clicked();

    void on_button_controllight_clicked();

    void on_lightmanual_clicked();

    void on_update_clicked();

private:
    Ui::MainWindow *ui;
    bool logincorrect;
    int timer;
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H
