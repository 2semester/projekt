#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_buttonBox_accepted()
{
    logincorrect = checklogin();
    this->close();
}

void login::on_buttonBox_rejected()
{
    this->close();
}

bool login::checklogin(){
    if(ui->lineEdit_2->text() == "asdf"){
        return true;
    }
    else{
        return false;
    }
}

bool login::correct(){
    return logincorrect;
}
