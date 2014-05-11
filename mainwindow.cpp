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
   mEditunits.giveptr(&c_enheder, &c_totalkonfiguration);//skal faa pointer til c_enheder
   mEditunits.redraw();
   mEditunits.exec();

   if(!c_totalkonfiguration.konfigurationliste.empty()){
    ui->button_controllight->setEnabled(true);
    ui->lightmanual->setEnabled(true);
   }
   else{
    ui->button_controllight->setEnabled(false);
    ui->lightmanual->setEnabled(false);
    }
}


void MainWindow::on_button_controllight_clicked()
{
    controllight mControllight;
    mControllight.setModal(true);
    mControllight.giveptr(&c_enheder, &c_totalkonfiguration); //skal faa pointer til c_enheder og c_totalkonfiguration
    mControllight.draw();
    mControllight.exec();
}


void MainWindow::on_lightmanual_clicked() //skal faa pointer til c_enheder
{
    ManualLight mManuallight;
    mManuallight.setModal(true);
    mManuallight.giveptr(&c_enheder);
    mManuallight.redraw();
    mManuallight.exec();
}

void MainWindow::on_update_clicked()
{
    //generate strings for units
    //generate strings for config
    //send strings for units
    //send strings for plans

}
