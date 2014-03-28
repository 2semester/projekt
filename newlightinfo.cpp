#include "newlightinfo.h"
#include "ui_newlightinfo.h"

newlightinfo::newlightinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newlightinfo)
{
    ui->setupUi(this);
    ui->TypeBox->addItem(tr("Light"));
}

newlightinfo::~newlightinfo()
{
    delete ui;
}

void newlightinfo::on_buttonBox_accepted()
{
    valid = true;
    name = ui->Name->text();
    desc = ui->Desc->text();
    type = ui->TypeBox->currentIndex();
    room = ui->RoomBox->currentIndex();
    this->close();
}

void newlightinfo::on_buttonBox_rejected()
{
    valid = false;
    this->close();
}

QString newlightinfo::returnName(){
    return name;
}
QString newlightinfo::returnDesc(){
    return desc;
}
int newlightinfo::returnType(){
    return type;
}
int newlightinfo::returnRoom(){
    return room;
}
