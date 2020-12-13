#ifndef HASHTABLEBYNAME_H
#define HASHTABLEBYNAME_H

#include "dentist.h"
#include <QString>
#include <QList>

class HashTableByName
{
public:
    struct Node
    {
        QString key;
        QList<Dentist*> listOfDentists;
    };

    HashTableByName();
    ~HashTableByName();
    void push(Dentist* currentOfDentist);
    void search(QString key, QList<Dentist*> *tmp);
    void searchAll(QList<Dentist*> *tmp);
    void clear();
private:
    Node* arr;
    int hashing(QString key);
    int size;
};

#endif // HASHTABLEBYNAME_H
