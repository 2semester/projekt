#include "sure.h"
#include "ui_sure.h"

sure::sure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sure)
{
    ui->setupUi(this);
}

sure::~sure()
{
    delete ui;
}

void sure::on_yes_clicked()
{
    answer = true;
    this->close();
}

void sure::on_no_clicked()
{
    answer = false;
    this->close();
}
