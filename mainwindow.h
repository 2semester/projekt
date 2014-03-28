#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_button_Login_clicked();

    void on_button_editunits_clicked();

    void on_button_controllight_clicked();

    void on_lightmanual_clicked();

private:
    Ui::MainWindow *ui;
    bool logincorrect;
};

#endif // MAINWINDOW_H
