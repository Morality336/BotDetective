#ifndef DENTIST_H
#define DENTIST_H
#include "dentistry.h"
#include <QString>
#include <QList>
class Comments{
public:
    Comments();
    void setCommentatorName(QString CommentatorName);
    void setComment(QString Comment);
    void setRating(double Rating);
    QString getCommentatorName();
    QString getComment();
    double getRating();
private:
    QString commentatorName;
    QString comment;
    double rating;
};

class Dentist
{
public:
    Dentist();
    Dentist(QString objJSON);
        ~Dentist();
        QString getFirstName();
        QString getLastName();
        QString getPatronymic();
        QString getSpecialization();
        QString getAboutDentist();
        QString getContactsDentist();
        int getYears();
        double getRating();
        int getWorkExperience();
        QString getPhoto();
        Dentistry getDentistry();
        int getIdOfDentistry();
        QList<Comments>& getListComments();

        void setFirstName(QString FirstName);
        void setLastName(QString LastName);
        void setPatronymic(QString Patronymic);
        void setSpecialization(QString Specialization);
        void setAboutDentist(QString AboutDentist);
        void setContactsDentist(QString ContactsDentist);
        void setYears(int Years);
        void setRating(double Rating);
        void setWorkExperience(int WorkExperience);
        void setPhoto(QString Photo);
        void setDentistry(Dentistry dentistry);
        void setIdOfDentistry(int idOfDentistry);
        void addListComments(Comments &comment);
        Dentist& operator=(Dentist& other);
        friend class Comments;
    private:
        Dentistry dentistry;
        QString firstName;
        QString lastName;
        QString patronymic;
        QString specialization;
        QString aboutDentist;
        QString contactsDentist;
        int years;
        double rating;
        int workExperience;
        int idOfDentistry;
        QString photo;
        QList<Comments> listComments;
    };


#endif // DENTIST_H
