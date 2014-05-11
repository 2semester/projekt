#include "manuallight.h"
#include "ui_manuallight.h"

ManualLight::ManualLight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManualLight)
{
    ui->setupUi(this);
    Vlayout = new QVBoxLayout;
}

ManualLight::~ManualLight()
{
    delete ui;
}

void ManualLight::ok(){
    for(int i = 0; i < ptrenheder->lysenheder.size(); i++){
        lysenhed tmplys = ptrenheder->lysenheder.at(i);
        tmplys.setstatus(checkbox[i]->isTristate());
    }
    this->close();
}

void ManualLight::fail(){
    this->close();
}

void ManualLight::giveptr(enheder *enhederptr){
    ptrenheder = enhederptr;
}

void ManualLight::redraw(){
    delete Vlayout;
    Vlayout = new QVBoxLayout;
    int lamps = ptrenheder->lysenheder.size();
    for(int i = 0; i < ptrenheder->lysenheder.size(); i++){
        label[i] = new QLabel;
        lamplabel[i] = new QLabel;
        lysenhed tmplys = ptrenheder->lysenheder.at(i);
        label[i]->setText(tmplys.getname());
        lamplabel[i]->setText((tmplys.getdesc()));
        checkbox[i] = new QCheckBox;

        layout[i] = new QHBoxLayout;
        layout[i]->addWidget(label[i]);
        layout[i]->addWidget(lamplabel[i]);
        layout[i]->addWidget(checkbox[i]);
        Vlayout->addLayout(layout[i]);

    }

    QHBoxLayout *boxlayout = new QHBoxLayout;
    QDialogButtonBox *button1 = new QDialogButtonBox(QDialogButtonBox::Ok);
        connect(button1, SIGNAL(clicked(QAbstractButton*)), this, SLOT(ok()));
    QDialogButtonBox *button2 = new QDialogButtonBox(QDialogButtonBox::Cancel);
        connect(button2, SIGNAL(clicked(QAbstractButton*)), this, SLOT(fail()));
    boxlayout->addWidget(button1);
    boxlayout->addWidget(button2);
    Vlayout->addLayout(boxlayout);
    window()->setLayout(Vlayout);
    window()->show();
}
