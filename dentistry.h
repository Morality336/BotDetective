#ifndef DENTISTRY_H
#define DENTISTRY_H

#include <QString>

class Dentistry
{
public:
    Dentistry();
    Dentistry(QString objJSON);
    ~Dentistry();
        QString getNameOfDentistry();
        QString getAddress();
        QString getWorkingHours();
        QString getAboutUs();
        QString getContactsDentistry();
        int getIdOfDentistry();

        void setNameOfDentistry(QString NameOfDentistry);
        void setAddress(QString Address);
        void setWorkingHours(QString WorkingHours);
        void setAboutUs(QString AboutUs);
        void setContactsDentistry(QString ContactsDentistry);
        void setIdOfDentistry(int idOfDentistry);

        Dentistry& operator=(Dentistry& other);
    private:
        QString nameOfDentistry;
        QString address;
        QString workingHours;
        QString aboutUs;
        QString contactsDentistry;
        int idOfDentistry;
};

#endif // DENTISTRY_H
