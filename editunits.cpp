#include "editunits.h"
#include "ui_editunits.h"
#include "sure.h"
#include "newlightinfo.h"


editunits::editunits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editunits)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    tableHeader<<"Type"<<"Name"<<"ID"<<"Description";
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
        lysenhed tmplys;
        type = mNewlightinfo.returnType();
        ID = mNewlightinfo.returnID();
        name = mNewlightinfo.returnName();
        desc = mNewlightinfo.returnDesc();
        tmplys.settype(type);
        tmplys.setID(ID);
        tmplys.setname(name);
        tmplys.setdesc(desc);
        ptrenheder->lysenheder.push_back(tmplys);

        int insertRow = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(insertRow);
        if(type == 0){
            ui->tableWidget->setItem(insertRow, 0, new QTableWidgetItem("Light"));
        }
        ui->tableWidget->setItem(insertRow, 1, new QTableWidgetItem(tmplys.getname()));
        ui->tableWidget->setItem(insertRow, 2, new QTableWidgetItem(QString::number(tmplys.getID()+1)));
        ui->tableWidget->setItem(insertRow, 3, new QTableWidgetItem(tmplys.getdesc()));
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

void editunits::giveptr(enheder *enhederptr){
    ptrenheder = enhederptr;

}
