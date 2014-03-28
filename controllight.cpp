#include "controllight.h"
#include "ui_controllight.h"

controllight::controllight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::controllight)
{
    ui->setupUi(this);
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

    ui->comboBox->addItem(tr("Test Lamp 1"));
    ui->comboBox->addItem(tr("Test Lamp 2"));
    ui->comboBox->addItem(tr("Test Lamp 3"));
}

controllight::~controllight()
{
    delete ui;
}

void controllight::on_ok_clicked()
{
    this->close();
}

void controllight::on_cancel_clicked()
{
    this->close();
}


void controllight::on_on_clicked()
{
    QTableWidgetSelectionRange range = ui->tableWidget->selectedRanges().front();

    for(int row = range.topRow(); row <= range.bottomRow(); row++){
        for(int column = range.leftColumn(); column <= range.rightColumn(); column++){
            ui->tableWidget->item(row,column)->setBackground(Qt::green);
            ui->tableWidget->item(row,column)->setText("ON");
        }
    }
}

void controllight::on_off_clicked()
{
    QTableWidgetSelectionRange range = ui->tableWidget->selectedRanges()[0];

    for(int row = range.topRow(); row <= range.bottomRow(); row++){
        for(int column = range.leftColumn(); column <= range.rightColumn(); column++){
            ui->tableWidget->item(row,column)->setBackground(Qt::red);
            ui->tableWidget->item(row,column)->setText("");
        }
    }
}

void controllight::on_comboBox_currentIndexChanged(int LampID)
{
    //temp save other lamp config and then load new data
    for(int row = 0; row < 24; row++){ //placeholder stuff
        for(int column = 0; column < 7; column++){
            ui->tableWidget->item(row,column)->setBackground(Qt::red);
            ui->tableWidget->item(row,column)->setText("");
        }
    }

}
