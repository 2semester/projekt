#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "editunits.h"
#include "controllight.h"
#include "manuallight.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    logincorrect = false;
    ui->button_editunits->setEnabled(false);
    ui->button_controllight->setEnabled(false);
    ui->lightmanual->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_Login_clicked()
{
   login mLogin;
   mLogin.setModal(true);
   if(mLogin.exec()){
       logincorrect = mLogin.correct();
       if(logincorrect){
           ui->button_editunits->setEnabled(true);
           ui->button_controllight->setEnabled(true);
           ui->lightmanual->setEnabled(true);
       }
       else{
           ui->button_editunits->setEnabled(false);
           ui->button_controllight->setEnabled(false);
           ui->lightmanual->setEnabled(false);
       }
   }
}

void MainWindow::on_button_editunits_clicked()
{
   editunits mEditunits;
   mEditunits.setModal(true);
   if(logincorrect){
       mEditunits.exec();
   }
}


void MainWindow::on_button_controllight_clicked()
{
    controllight mControllight;
    mControllight.setModal(true);
    if(logincorrect){
        mControllight.exec();
    }
}


void MainWindow::on_lightmanual_clicked()
{
    ManualLight mManuallight;
    mManuallight.setModal(true);
    if(logincorrect){
        mManuallight.exec();
    }
}
