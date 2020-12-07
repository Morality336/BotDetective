#ifndef HASHTABLEBYNAMEOFDENTISTRY_H
#define HASHTABLEBYNAMEOFDENTISTRY_H


#include "dentist.h"
#include <QString>
#include <QList>

class HashTableByNameOfDentistry
{
public:
    struct Node
    {
        QString key;
        QList<Dentist*> listOfDentists;
    };

    HashTableByNameOfDentistry();
    ~HashTableByNameOfDentistry();
    void push(Dentist* currentOfDentist);
    void search(QString key, QList<Dentist*> *temp);
    void clear();
private:
    Node* arr;
    int hashing(QString key);
    int size;
};

#endif // HASHTABLEBYNAMEOFDENTISTRY_H
