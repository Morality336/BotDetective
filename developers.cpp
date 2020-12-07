#include "developers.h"
#include "ui_developers.h"

Developers::Developers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Developers)
{
    ui->setupUi(this);
}

Developers::~Developers()
{
    delete ui;
}
void Developers::SendInterface(QJsonDocument &interface){
    ui->DevelopersText->setText(interface.object().value("DevelopersText").toString());
}
