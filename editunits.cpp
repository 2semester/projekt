#include "editunits.h"
#include "ui_editunits.h"
#include "sure.h"
#include "newlightinfo.h"
#include <iostream>

editunits::editunits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editunits)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    tableHeader<<"Type"<<"Name"<<"Room"<<"Description";
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
}

editunits::~editunits()
{
    delete ui;
}


void editunits::on_Add_clicked()
{

    newlightinfo mNewlightinfo;
    mNewlightinfo.setModal(true);
    mNewlightinfo.exec();
    if(mNewlightinfo.valid){
        type = mNewlightinfo.returnType();
        room = mNewlightinfo.returnRoom();
        name = mNewlightinfo.returnName();
        desc = mNewlightinfo.returnDesc();
        const int currentRow = ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(currentRow+1);
        if(type == 0){
            ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem("Light"));
        }
        ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(name));
        switch(room){
        case -1:
            ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem("N/A"));
            break;
        default:
            ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem("N/A"));
            break;
        }

        ui->tableWidget->setItem(currentRow, 3, new QTableWidgetItem(desc));
    }
}

void editunits::on_remove_clicked()
{
    if(!ui->tableWidget->selectedRanges().empty()){ //check if anything is selected
        sure mSure;
        mSure.setModal(true);
        mSure.exec();
        if(mSure.answer){
            int selectedRow = ui->tableWidget->selectedRanges().front().topRow();
            ui->tableWidget->removeRow(selectedRow);
        }
    }
}

void editunits::on_ok_clicked()
{
    //save stuff
    this->close();
}

void editunits::on_cancel_clicked()
{
    this->close();
}
