#include "manuallight.h"
#include "ui_manuallight.h"

ManualLight::ManualLight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManualLight)
{
    ui->setupUi(this);
    int lamps = 7;


    for(int i=0; i< lamps; i++){
       lamplabel[i] = new QLabel;
       lamplabel[i]->setText("Lamp");
    }

    for(int i=0; i< lamps; i++){
       label[i] = new QLabel;
       label[i]->setText(QString::number(i));
    }

    for(int i=0; i< lamps; i++){
       checkbox[i] = new QCheckBox;
    }

    for(int i=0; i< lamps; i++){
       layout[i] = new QHBoxLayout;
       layout[i]->addWidget(lamplabel[i]);
       layout[i]->addWidget(label[i]);
       layout[i]->addWidget(checkbox[i]);
    }
    QVBoxLayout *Vlayout = new QVBoxLayout;
    for(int i = 0; i < lamps; i++){
        Vlayout->addLayout(layout[i]);
    }

    QDialogButtonBox *button1 = new QDialogButtonBox(QDialogButtonBox::Ok);
        connect(button1, SIGNAL(clicked(QAbstractButton*)), this, SLOT(ok()));
    QDialogButtonBox *button2 = new QDialogButtonBox(QDialogButtonBox::Cancel);
        connect(button2, SIGNAL(clicked(QAbstractButton*)), this, SLOT(fail()));
    QHBoxLayout *boxlayout = new QHBoxLayout;
    boxlayout->addWidget(button1);
    boxlayout->addWidget(button2);
    Vlayout->addLayout(boxlayout);
    window()->setLayout(Vlayout);
    window()->show();

}

ManualLight::~ManualLight()
{
    delete ui;
}

void ManualLight::ok(){
    //some save and process stuff
    this->close();
}

void ManualLight::fail(){
    this->close();
}

void ManualLight::giveptr(enheder *enhederptr){

}
