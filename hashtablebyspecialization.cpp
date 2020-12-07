#include "hashtablebyspecialization.h"

HashTableBySpecialization::HashTableBySpecialization()
{
    size = 1000;
    arr = new Node[size];
    keyWordsForSearchBySpec = new QList<QPair<QString, QList<QString>>>;
}
HashTableBySpecialization::~HashTableBySpecialization()
{
    delete[] arr;
}
void HashTableBySpecialization::push(Dentist *currentOfDentist)
{
    int id = hashing(currentOfDentist->getSpecialization());
    arr[id].listOfDentists.push_back(currentOfDentist);
    arr[id].key = currentOfDentist->getSpecialization().toLower();
}
int HashTableBySpecialization::hashing(QString key)
{
    int hash_result = 0;
    key = key.toLower();
    for (int i = 0; i < key.size(); i++)//хеширование по трем первым буквам
    {
        hash_result = (hash_result + key[i].unicode()) % size;
    }
    return hash_result;
}
void HashTableBySpecialization::search(QString key, QList<Dentist*> *temp)
{
    key = key.toLower();
    int id = hashing(key);

    if(arr[id].listOfDentists.size() == 0)
    {
        QString newKey = searchByKeyWords(key);
        if (newKey != key)
        {
            search(newKey, temp);
        }
    }

    for(int i = 0; i < arr[id].listOfDentists.size(); i++)
    {
        int success = 0;
        int sizevalue = key.size();
        for(int j = 0; j < sizevalue; j++){
        if (arr[id].listOfDentists.at(i)->getSpecialization()[j].toLower() == key[j])
            ++success;

        }
        double res = success / sizevalue;
        if(res >= 0.65){
                   temp->append(arr[id].listOfDentists.at(i));
        }
    }
}

void HashTableBySpecialization::setKeyWords(QList<QPair<QString, QList<QString>>> *keyWordsForSearchBySpec)
{
//    for(int i = 0; i < keyWordsForSearchBySpec->size(); i++)
//    {
//        for(int j = 0; j < keyWordsForSearchBySpec->at(i).second.size(); j++)
//       {
//             keyWordsForSearchBySpec->at(i).second.at(j) = keyWordsForSearchBySpec->at(i).second.at(j).toLower();
//       }
//   }
    this->keyWordsForSearchBySpec = keyWordsForSearchBySpec;
}

QString HashTableBySpecialization::searchByKeyWords(QString keyWords)
{
//    keyWords = keyWords.toLower();
    for (int i = 0; i < keyWordsForSearchBySpec->size(); i++)
    {
        for (int j = 0; j < keyWordsForSearchBySpec->at(i).second.size(); j++)
        {
            int firstSym = keyWords.toStdString().find(keyWordsForSearchBySpec->at(i).second.at(j).toLower().toStdString());
            if(firstSym >= 0 /*&& firstSym < keyWords.size()*/)
            {
                keyWords = keyWordsForSearchBySpec->at(i).first;
                return keyWords;
            }
        }
    }
    return keyWords;
}
void HashTableBySpecialization::clear()
{
    for(int i = 0; i < size; i++)
    {
        arr[i].key = "";
        arr[i].listOfDentists.clear();
    }
}
