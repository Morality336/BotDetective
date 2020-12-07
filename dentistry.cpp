#include "dentistry.h"

Dentistry::Dentistry()
{
    nameOfDentistry = "Empty";
    address = "Empty";
    workingHours = "Empty";
    aboutUs = "Empty";
    contactsDentistry = "Empty";
    idOfDentistry = -1;
}
Dentistry::~Dentistry() {}

QString Dentistry::getNameOfDentistry() {return this->nameOfDentistry;}
QString Dentistry::getAddress() {return this->address;}
QString Dentistry::getWorkingHours() {return this->workingHours;}
QString Dentistry::getAboutUs() {return this->aboutUs;}
QString Dentistry::getContactsDentistry() {return this->contactsDentistry;}
int Dentistry::getIdOfDentistry() {return this->idOfDentistry;}

void Dentistry::setNameOfDentistry(QString NameOfDentistry) {this->nameOfDentistry = NameOfDentistry;}
void Dentistry::setAddress(QString Address) {this->address = Address;}
void Dentistry::setWorkingHours(QString WorkingHours) {this->workingHours = WorkingHours;}
void Dentistry::setAboutUs(QString AboutUs) {this->aboutUs = AboutUs;}
void Dentistry::setContactsDentistry(QString ContactsDentistry) { this->contactsDentistry = ContactsDentistry;}
void Dentistry::setIdOfDentistry(int idOfDentistry) {this->idOfDentistry = idOfDentistry;}

Dentistry& Dentistry::operator=(Dentistry& other)
{
    this->nameOfDentistry = other.nameOfDentistry;
    this->workingHours = other.workingHours;
    this->address = other.address;
    this->aboutUs = other.aboutUs;
    this->contactsDentistry = other.contactsDentistry;
    this->idOfDentistry = other.idOfDentistry;
    return *this;
}
