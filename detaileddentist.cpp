#include "detaileddentist.h"
#include "ui_detaileddentist.h"
#include <QPixmap>
DetailedDentist::DetailedDentist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailedDentist)
{
    ui->setupUi(this);
}

DetailedDentist::~DetailedDentist()
{
    delete ui;
}

void DetailedDentist::sendDentist(Dentist* temp, QJsonDocument &interface){
    QPixmap pix("ImageDentists/" + temp->getPhoto());
    if (pix.isNull())
    {
       QPixmap noAvatarPix("ImageDentists/no-avatar.PNG");
       ui->photo->setPixmap(noAvatarPix.scaled(360,270));
    }
    else
    {
        ui->photo->setPixmap(pix.scaled(360,270));
    }
    ui->FirstName->setText(interface.object().value("FirstName").toString() + ": " + temp->getFirstName());
     ui->LastName->setText(interface.object().value("LastName").toString() + ": " + temp->getLastName());
      ui->Patronymic->setText(interface.object().value("Patronymic").toString() + ": " + temp->getPatronymic());
       ui->Years->setText(interface.object().value("Years").toString() + ": " + QString::number(temp->getYears()));
        ui->WorkExperience->setText(interface.object().value("WorkExperience").toString() + ": " + QString::number(temp->getWorkExperience()));
         ui->WorkingHours->setText(interface.object().value("WorkingHours").toString() + ": " + temp->getDentistry().getWorkingHours());
          ui->Address->setText(interface.object().value("Address").toString() + ": " + temp->getDentistry().getAddress());
           ui->AboutUs->setText(interface.object().value("AboutUs").toString() + ": " + temp->getDentistry().getAboutUs());
            ui->ContactsDentistry->setText(interface.object().value("ContactsDentistry").toString() + ": " + temp->getDentistry().getContactsDentistry());
             ui->NameOfDentistry->setText(interface.object().value("NameOfDentistry").toString() + ": " + temp->getDentistry().getNameOfDentistry());
              ui->ContactsDentist->setText(interface.object().value("ContactsDentist").toString() + ": " + temp->getContactsDentist());
               ui->Rating->setText(interface.object().value("Rating").toString() + ": " + QString::number(temp->getRating()));
               ui->AboutDentist->setText(interface.object().value("AboutDentist").toString() + ": " + temp->getAboutDentist());
               ui->Specialization->setText(interface.object().value("Specialization").toString() + ": " + temp->getSpecialization());

}
