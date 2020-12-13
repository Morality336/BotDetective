#include "hashtablebynameofdentistry.h"

HashTableByNameOfDentistry::HashTableByNameOfDentistry()
{
    size = 30;
    arr = new Node[size];
}
HashTableByNameOfDentistry::~HashTableByNameOfDentistry()
{
    delete[] arr;
}
void HashTableByNameOfDentistry::push(Dentist *currentOfDentist)
{
    int id = hashing(currentOfDentist->getDentistry().getNameOfDentistry());
    arr[id].listOfDentists.push_back(currentOfDentist);
    arr[id].key = currentOfDentist->getDentistry().getNameOfDentistry().toLower();
}
int HashTableByNameOfDentistry::hashing(QString key)
{
    int hash_result = 0;
    key = key.toLower();
    for (int i = 0; i < 3; i++)//хеширование по трем первым буквам
    {
        hash_result = (hash_result + key[i].unicode()) % size;
    }
    return hash_result;
}
void HashTableByNameOfDentistry::search(QString key, QList<Dentist*> *temp)
{
    key = key.toLower();
    int id = hashing(key);
    for(int i = 0;i < arr[id].listOfDentists.size(); i++){
        int success = 0;
                int sizevalue = key.size();
                for(int j = 0; j < sizevalue; j++){
                if (arr[id].listOfDentists.at(i)->getDentistry().getNameOfDentistry()[j].toLower() == key[j])
                    ++success;

                }
                double res = success / sizevalue;
                if(res >= 0.65){
                   temp->append(arr[id].listOfDentists.at(i));
                }
            }
}

void HashTableByNameOfDentistry::clear()
{
    for(int i = 0; i < size; i++)
    {
        arr[i].key = "";
        arr[i].listOfDentists.clear();
    }
}
