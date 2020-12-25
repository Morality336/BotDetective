#include "hashtablebyname.h"
HashTableByName::HashTableByName()
{
    size = 100;
    arr = new Node[size];
}
HashTableByName::~HashTableByName()
{
    delete[] arr;
}
void HashTableByName::push(Dentist *currentOfDentist)
{
    int id = hashing(currentOfDentist->getLastName());
    arr[id].listOfDentists.push_back(currentOfDentist);
    arr[id].key = currentOfDentist->getLastName().toLower();
}
int HashTableByName::hashing(QString key)
{
    int hash_result = 0;
    key = key.toLower();
    for (int i = 0; i < 3; i++)//хеширование по трем первым буквам
    {
        hash_result = (hash_result + key[i].unicode()) % size;
    }
    return hash_result;
}
void HashTableByName::search(QString key, QList<Dentist*> *temp)
{
    key = key.toLower();
    int id = hashing(key);
    for(int i = 0;i < arr[id].listOfDentists.size(); i++){
        int success = 0;
                int sizevalue = key.size();
                for(int j = 0; j < sizevalue; j++){
                if (arr[id].listOfDentists.at(i)->getLastName()[j].toLower() == key[j])
                    ++success;

                }
                double res = success / sizevalue;
                if(res >= 0.65){
                   temp->append(arr[id].listOfDentists.at(i));
                }
            }
}
void HashTableByName::searchAll(QList<Dentist*> *tmp){
    for(int i = 0; i < size; i++){
        if(arr[i].listOfDentists.size() != 0){
            for(int j = 0; j < arr[i].listOfDentists.size(); j++){
             tmp->append(arr[i].listOfDentists.at(j));
            }
        }
    }
}

void HashTableByName::clear()
{
    delete arr;
    arr = new Node[size];
}
