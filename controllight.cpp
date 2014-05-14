#include "controllight.h"
#include "ui_controllight.h"

controllight::controllight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::controllight)
{
    ui->setupUi(this);

}

controllight::~controllight()
{
    delete ui;
}

void controllight::on_ok_clicked()
{
    this->close();
}

void controllight::on_on_clicked()
{
    konfiguration tmpkonfig = ptrkonfig->konfigurationliste.at(ui->comboBox->currentIndex());
    if(!ui->tableWidget->selectedRanges().empty()){
        QTableWidgetSelectionRange range = ui->tableWidget->selectedRanges().front();
        for(int row = range.topRow(); row <= range.bottomRow(); row++){
            for(int column = range.leftColumn(); column <= range.rightColumn(); column++){
                tmpkonfig.setstatus(row,column,true);

            }
        }
    }
    ptrkonfig->konfigurationliste.at(ui->comboBox->currentIndex()) = tmpkonfig;
    redraw();
}

void controllight::on_off_clicked()
{
    konfiguration tmpkonfig = ptrkonfig->konfigurationliste.at(ui->comboBox->currentIndex());
    if(!ui->tableWidget->selectedRanges().empty()){
        QTableWidgetSelectionRange range = ui->tableWidget->selectedRanges().front();
        for(int row = range.topRow(); row <= range.bottomRow(); row++){
            for(int column = range.leftColumn(); column <= range.rightColumn(); column++){
                tmpkonfig.setstatus(row,column,false);

            }
        }
    }
    ptrkonfig->konfigurationliste.at(ui->comboBox->currentIndex()) = tmpkonfig;
    redraw();
}

void controllight::on_comboBox_currentIndexChanged(int LampID)
{
    redraw();

}

void controllight::giveptr(enheder *enhedptr, totalkonfiguration *konfigptr){
    ptrenheder = enhedptr;
    ptrkonfig = konfigptr;
}

void controllight::draw(){
    ui->tableWidget->setRowCount(24);
    ui->tableWidget->setColumnCount(7);
    tableHeader<<"Monday"<<"Tuesday"<<"Wednesday"<<"Thursday"<<"Friday"<<"Saturday"<<"Sunday";
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    for(int row = 0; row < 24; row++){
        for(int column = 0; column < 7; column++){
            ui->tableWidget->setItem(row, column,new QTableWidgetItem);
            ui->tableWidget->item(row,column)->setBackground(Qt::red);
        }
    }
    for(int i = 0; i < ptrenheder->lysenheder.size(); i++){
        lysenhed tmplys = ptrenheder->lysenheder.at(i);
        ui->comboBox->addItem(tmplys.getname());
    }
}

void controllight::redraw(){

    konfiguration tmpkonfig = ptrkonfig->konfigurationliste.at(ui->comboBox->currentIndex());
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(24);
    ui->tableWidget->setColumnCount(7);
    tableHeader<<"Monday"<<"Tuesday"<<"Wednesday"<<"Thursday"<<"Friday"<<"Saturday"<<"Sunday";
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);

    for(int row = 0; row < 24; row++){
        for(int column = 0; column < 7; column++){
            ui->tableWidget->setItem(row, column,new QTableWidgetItem);
            if(tmpkonfig.getstatus(row,column) == true){
                ui->tableWidget->item(row,column)->setBackground(Qt::green);
                ui->tableWidget->item(row,column)->setText("ON");
            }
            else{
                ui->tableWidget->item(row,column)->setBackground(Qt::red);
                ui->tableWidget->item(row,column)->setText("");
            }
        }
    }
}
