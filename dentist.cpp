
#include "dentist.h"

Dentist::Dentist()
{
    firstName = "Empty";
    lastName = "Empty";
    patronymic = "Empty";
    specialization = "Empty";
    aboutDentist = "Empty";
    contactsDentist = "Empty";
    years = NULL;
    rating = NULL;
    workExperience = NULL;
    idOfDentistry = -1;
}
Dentist::~Dentist() {}

QString Dentist::getFirstName() {return this->firstName;}
QString Dentist::getLastName() {return this->lastName;}
QString Dentist::getPatronymic() {return this->patronymic;}
QString Dentist::getSpecialization() {return this->specialization;}
QString Dentist::getAboutDentist() {return this->aboutDentist;}
QString Dentist::getContactsDentist() {return this->contactsDentist;}
QString Dentist::getPhoto(){return this->photo;}
Dentistry Dentist::getDentistry(){return dentistry;}
int Dentist::getYears() {return this->years;}
double Dentist::getRating() {return this->rating;}
int Dentist::getWorkExperience() {return this->workExperience;}
int Dentist::getIdOfDentistry(){return idOfDentistry;}
QList<Comments>& Dentist::getListComments(){return this->listComments;}

void Dentist::setFirstName(QString FirstName) {this->firstName = FirstName;}
void Dentist::setLastName(QString LastName){this->lastName = LastName;}
void Dentist::setPatronymic(QString Patronymic) {this->patronymic = Patronymic;}
void Dentist::setSpecialization(QString Specialization) {this->specialization = Specialization;}
void Dentist::setAboutDentist(QString AboutDentist) {this->aboutDentist = AboutDentist;}
void Dentist::setContactsDentist(QString ContactsDentist) {this->contactsDentist = ContactsDentist;}
void Dentist::setYears(int Years) {this->years = Years;}
void Dentist::setRating(double Rating) {this->rating = Rating;}
void Dentist::setWorkExperience(int WorkExperience) {this->workExperience = WorkExperience;}
void Dentist::setPhoto(QString Photo){this->photo = Photo;}
void Dentist::setDentistry(Dentistry dentistry){this->dentistry = dentistry;}
void Dentist::setIdOfDentistry(int idOfDentistry){this->idOfDentistry = idOfDentistry;}
void Dentist::addListComments(Comments &comment){listComments.append(comment);}
Dentist& Dentist::operator=(Dentist& other)
{
    this->photo = other.photo;
    this->years = other.years;
    this->rating = other.rating;
    this->lastName = other.lastName;
    this->dentistry = other.dentistry;
    this->firstName = other.firstName;
    this->patronymic = other.patronymic;
    this->aboutDentist = other.aboutDentist;
    this->specialization = other.specialization;
    this->workExperience = other.workExperience;
    this->contactsDentist = other.contactsDentist;
    this->listComments = other.listComments;
    return *this;
}
Comments::Comments(){
    comment = "Empty";
    commentatorName = "Empty";
    rating = -1;
}
void Comments::setCommentatorName(QString CommentatorName){this->commentatorName = CommentatorName;}
void Comments::setComment(QString Comment){this->comment = Comment;}
void Comments::setRating(double Rating){this->rating = Rating;}
QString Comments::getCommentatorName(){return this->commentatorName;}
QString Comments::getComment(){return this->comment;}
double Comments::getRating(){return this->rating;}
