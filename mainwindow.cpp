#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dentist.h"
#include "exception.h"
#include <QTextEdit>
#include <QTextStream>
#include <QMessageBox>
#include <QTime>
#include <QScrollArea>
#include <QLabel>

class dentist;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pathFileDentist = "../BotDetective-main/Date/dentist_eng.json";
    pathFileDentistry = "../BotDetective-main/Date/dentistry_eng.db";
    pathFileSpec = "../BotDetective-main/Date/spec_eng.json";
    pathInterface = "../BotDetective-main/Date/interface_eng.json";
    OpenInterface();
    OpenSpec();
    OpenDentistry();
    OpenDentist();
}

void MainWindow::OpenSpec(){
    try{
        QFile fileSpec(pathFileSpec);
        if(!fileSpec.open(QIODevice::ReadOnly|QFile::Text))
        {
            throw 4;
        }
        else{
            specialization.clear();
            dateDentist = QJsonDocument::fromJson(QByteArray(fileSpec.readAll()));
            QPair<QString,QList<QString>> temp;
            temp.first = interface.object().value("Dentist-therapist").toString();
            dateSpecArr = QJsonValue(dateDentist.object().value("Dentist-therapist")).toArray();
            QString tempText;
            for(int i =0; i < dateSpecArr.count();i++){
            tempText = dateSpecArr[i].toString();
            temp.second.append(tempText);
            }
            specialization.append(temp);
            temp.second.clear();
            temp.first = interface.object().value("Dentist-surgeon-implantologist").toString();
            dateSpecArr = QJsonValue(dateDentist.object().value("Dentist-surgeon-implantologist")).toArray();
            for(int i =0; i < dateSpecArr.count();i++){
            tempText = dateSpecArr[i].toString();
            temp.second.append(tempText);
            }
            specialization.append(temp);
            temp.second.clear();
            temp.first = interface.object().value("Dentist-periodontist").toString();
            dateSpecArr = QJsonValue(dateDentist.object().value("Dentist-periodontist")).toArray();
            for(int i =0; i < dateSpecArr.count();i++){
            tempText = dateSpecArr[i].toString();
            temp.second.append(tempText);
            }
            specialization.append(temp);
            temp.second.clear();
            temp.first = interface.object().value("Dentist-orthopedist").toString();
            dateSpecArr = QJsonValue(dateDentist.object().value("Dentist-orthopedist")).toArray();
            for(int i =0; i < dateSpecArr.count();i++){
            tempText = dateSpecArr[i].toString();
            temp.second.append(tempText);
            }
            specialization.append(temp);
            temp.second.clear();
            temp.first = interface.object().value("Dentist-orthodontist").toString();
            dateSpecArr = QJsonValue(dateDentist.object().value("Dentist-orthodontist")).toArray();
            for(int i =0; i < dateSpecArr.count();i++){
            tempText = dateSpecArr[i].toString();
            temp.second.append(tempText);
            }
            specialization.append(temp);
            temp.second.clear();
            temp.first = interface.object().value("Children's dentist").toString();
            dateSpecArr = QJsonValue(dateDentist.object().value("Children's dentist")).toArray();
            for(int i =0; i < dateSpecArr.count();i++){
            tempText = dateSpecArr[i].toString();
            temp.second.append(tempText);
            }
            specialization.append(temp);
            temp.second.clear();
            hashTableBySpecialization.setKeyWords(&specialization);
        }
        fileSpec.close();
    }
    catch(int error){
        MyException ex(error, interface);
    }
}

void MainWindow::OpenDentist(){
    try{
        QFile fileDoctors(pathFileDentist);
        if(!fileDoctors.open(QIODevice::ReadOnly|QFile::Text)){
            throw 5;
        }
        else {
            listDentist.clear();
            dateDentist = QJsonDocument::fromJson(QByteArray(fileDoctors.readAll()));
            dateDentistArr = QJsonValue(dateDentist.object().value("Doctors")).toArray();
            for(int i =0; i < dateDentistArr.count(); i++)
            {
                Dentist* temp = new Dentist();
                temp->setFirstName(dateDentistArr.at(i).toObject().value("firstName").toString());
                temp->setLastName(dateDentistArr.at(i).toObject().value("lastName").toString());
                temp->setPatronymic(dateDentistArr.at(i).toObject().value("patronymic").toString());
                temp->setYears(dateDentistArr.at(i).toObject().value("years").toInt());
                temp->setSpecialization(dateDentistArr.at(i).toObject().value("specialization").toString());
                temp->setAboutDentist(dateDentistArr.at(i).toObject().value("aboutDentist").toString());
                temp->setContactsDentist(dateDentistArr.at(i).toObject().value("contactsDentis").toString());
                temp->setWorkExperience(dateDentistArr.at(i).toObject().value("workExperience").toInt());
                temp->setPhoto(dateDentistArr.at(i).toObject().value("photo").toString());
                temp->setIdOfDentistry(dateDentistArr.at(i).toObject().value("idOfDentistry").toInt());
                QJsonArray dateCommentsArr = dateDentistArr.at(i).toObject().value("comments").toArray();
                double tempRating = 0;
                for(int k = 0; k < dateCommentsArr.count(); k++){
                    Comments * tmp = new Comments();
                    tmp->setCommentatorName(dateCommentsArr.at(k).toObject().value("commentatorName").toString());
                    tmp->setComment(dateCommentsArr.at(k).toObject().value("comment").toString());
                    tmp->setRating(dateCommentsArr.at(k).toObject().value("rating").toDouble());
                    tempRating += dateCommentsArr.at(k).toObject().value("rating").toDouble();
                    temp->addListComments(*tmp);
                }
                if(dateCommentsArr.count() != 0)
                    temp->setRating(tempRating / dateCommentsArr.count());
                else
                    temp->setRating(0);

                for (int j = 0; j < listDentistry.count(); j++)
                {
                    if (temp->getIdOfDentistry() == listDentistry.at(j)->getIdOfDentistry())
                    {
                        temp->setDentistry(*listDentistry.at(j));
                        break;
                    }
                }
                listDentist.append(temp);
            }
        }
        fileDoctors.close();
        hashTableByName.clear();
        hashTableByNameOfDentistry.clear();
        hashTableBySpecialization.clear();
        for(int j =0; j < listDentist.size(); j++){
            hashTableByName.push(listDentist.at(j));
            hashTableByNameOfDentistry.push(listDentist.at(j));
            hashTableBySpecialization.push(listDentist.at(j));
        }
    }
    catch(int error){
        MyException ex(error, interface);
    }
}

void MainWindow::OpenDentistry(){
    try{
        QSqlDatabase fileDentistry;
        fileDentistry =  QSqlDatabase::addDatabase("QSQLITE");
        fileDentistry.setDatabaseName(pathFileDentistry);
        if(!fileDentistry.open())
        {
            throw 6;
        }
        else
        {
            QSqlQuery query;
            query.exec("SELECT nameOfDentistry, address, workingHours, aboutUs, contactsDentistry, idOfDentistry FROM Dentistry");
            listDentistry.clear();

            while (query.next())
            {
                Dentistry* temp = new Dentistry();
                temp->setNameOfDentistry(query.value(0).toString());
                temp->setAddress(query.value(1).toString());
                temp->setWorkingHours(query.value(2).toString());
                temp->setAboutUs(query.value(3).toString());
                temp->setContactsDentistry(query.value(4).toString());
                temp->setIdOfDentistry(query.value(5).toInt());
                listDentistry.append(temp);
            }
        }
        fileDentistry.close();
    }
    catch(int error){
        MyException ex(error, interface);
    }
}

void MainWindow::OpenInterface(){
    try{
        QFile fileInterface(pathInterface);
        if(!fileInterface.open(QIODevice::ReadOnly|QFile::Text))
        {
            throw 7;
        }
        else{
            ui->BotOut->clear();
            ui->SearchBy->clear();
            ui->SortBy->clear();
            interface = QJsonDocument::fromJson(QByteArray(fileInterface.readAll()));
            ui->SearchBy->addItem(interface.object().value("SearchBySurname").toString());
            ui->SearchBy->addItem(interface.object().value("SearchBySpecialization").toString());
            ui->SearchBy->addItem(interface.object().value("SearchByDentistry").toString());
            ui->SortBy->addItem(interface.object().value("SortByRating").toString());
            ui->SortBy->addItem(interface.object().value("SortByAscending").toString());
            ui->SortBy->addItem(interface.object().value("SortByDescending").toString());
            ui->BotOut->setAlignment(Qt::AlignLeft);
            QTime cur = QTime::currentTime();
            if(cur.hour() >= 6 && cur.hour() <= 12)
                ui->BotOut->append(interface.object().value("GoodMorning").toString());
            else if(cur.hour() > 12 && cur.hour() < 18)
                ui->BotOut->append(interface.object().value("GoodAfternoon").toString());
            else
                ui->BotOut->append(interface.object().value("GoodEvening").toString());
            ui->BotOut->append(interface.object().value("Welcome").toString());
            ui->Send->setText(interface.object().value("Search").toString());
            ui->menuHelp->setTitle(interface.object().value("Menu").toString());
            ui->actHelp->setText(interface.object().value("Help").toString());
            ui->actDevelops->setText(interface.object().value("Developers").toString());
            ui->actionDentistry->setText(interface.object().value("AllDentistry").toString());
            ui->actionDentists->setText(interface.object().value("AllDentists").toString());
            ui->actionSpecializations->setText(interface.object().value("AllSpecializations").toString());
            ui->menuShow_All->setTitle(interface.object().value("ShowAll").toString());
            ui->actionClose->setText(interface.object().value("Close").toString());
        }
        fileInterface.close();
    }
    catch(int error){
        MyException ex(error, interface);
    }
}
MainWindow::~MainWindow()
{
    SaveDentist();
    delete ui;
}
void MainWindow::on_Send_clicked()
{
    try{
        int searchBy = ui->SearchBy->currentIndex();
        QString SearchWord = ui->MessageIn->text();
        if(SearchWord == "")
            throw 1;
        else
        {
            ui->BotOut->append("<p style='color:#258BBE'>" + SearchWord + "</p>");
            ui->MessageIn->clear();
            switch(searchBy)
            {
            case 0: SearchByName(SearchWord); break;
            case 1: SearchBySpecialization(SearchWord); break;
            case 2: SearchByDentistry(SearchWord); break;
            }
        }
    }
    catch(int error){
        MyException ex(error, interface);
    }
}

void MainWindow::SearchByName(QString SearchWord)
{
    try
    {
        QList<Dentist*> temp;
        temp.clear();
        hashTableByName.search(SearchWord, &temp);
        if (temp.isEmpty())
        {
            throw 1;
        }
        else
        {
            switch (ui->SortBy->currentIndex()) {
                case 0: sortByRating(&temp);
                break;
                case 1 : sortByAscending(&temp);
                break;
                case 2: sortByDescending(&temp);
                break;
            }
            ShowDentist(&temp);

        }
    }
    catch(int error)
    {
        MyException ex(error, interface, SearchWord);
    }
}
void MainWindow::SearchBySpecialization(QString SearchWord)
{
    try
    {
        QList<Dentist*> temp;
        temp.clear();
        hashTableBySpecialization.search(SearchWord, &temp);
        if (temp.isEmpty())
        {
            throw 2;
        }
        else
        {
            switch (ui->SortBy->currentIndex()) {
                case 0: sortByRating(&temp);
                break;
                case 1 : sortByAscending(&temp);
                break;
                case 2: sortByDescending(&temp);
                break;
            }
            ShowDentist(&temp);
        }
    }
    catch(int error)
    {
        MyException ex(error, interface, SearchWord);
    }
}
void MainWindow::SearchByDentistry(QString SearchWord)
{
    try
    {
        QList<Dentist*> temp;
        temp.clear();
        hashTableByNameOfDentistry.search(SearchWord, &temp);
        if (temp.isEmpty())
        {
            throw 3;
        }
        else
        {
            switch (ui->SortBy->currentIndex()) {
                case 0: sortByRating(&temp);
                break;
                case 1 : sortByAscending(&temp);
                break;
                case 2: sortByDescending(&temp);
                break;
            }
                ShowDentist(&temp);
        }
    }
    catch(int error)
    {
        MyException ex(error, interface, SearchWord);
    }
}

void MainWindow::sortByRating(QList<Dentist*> *list)
{
        for (int i = 0; i < list->size() - 1; i++)
        {
            for (int j = 0; j < list->size() - i - 1; j++)
            {
                if (list->at(j)->getRating() < list->at(j + 1)->getRating())
                {
                    Dentist* tmp = new Dentist;
                    *tmp = *list->at(j);
                    *list->at(j) = *list->at(j + 1);
                    *list->at(j + 1) = *tmp;
                    delete tmp;
                }
            }
        }
}
void MainWindow::sortByAscending(QList<Dentist *> *list)
{
        for (int i = 0; i < list->size() - 1; i++)
        {
            for (int j = 0; j < list->size() - 1; j++)
            {
                for(int z = 0; z < list->at(j)->getLastName().size(); z++){
                    if(list->at(j)->getLastName().at(z).unicode() > list->at(j+1)->getLastName().at(z).unicode()){
                        Dentist *temp = new Dentist;
                        *temp = *list->at(j);
                        list->removeAt(j);
                        list->insert(j+1,temp);
                        break;
                    }
                    else if(list->at(j)->getLastName().at(z).unicode() == list->at(j+1)->getLastName().at(z).unicode())
                        continue;
                    else
                        break;
                }
            }
        }
}
void MainWindow::sortByDescending(QList<Dentist*> *list)
{
    for (int i = 0; i < list->size() - 1; i++)
    {
        for (int j = 0; j < list->size() - 1; j++)
        {
            for(int z = 0; z < list->at(j)->getLastName().size(); z++){
                if(list->at(j)->getLastName().at(z).unicode() < list->at(j+1)->getLastName().at(z).unicode()){
                    Dentist *temp = new Dentist;
                    *temp = *list->at(j);
                    list->removeAt(j);
                    list->insert(j+1,temp);
                    break;
                }
                else if(list->at(j)->getLastName().at(z).unicode() == list->at(j+1)->getLastName().at(z).unicode())
                    continue;
                else
                    break;
            }
        }
    }
}

void MainWindow::ShowDentist(QList<Dentist*> *temp)
{
    QVBoxLayout *VLayout = new QVBoxLayout;
    QWidget* scrollAreaContent = new QWidget;
    ui->scrollArea->setWidget(scrollAreaContent);
            for(int i = 0; i < temp->size();i++){
                QVBoxLayout *DentistInfo = new QVBoxLayout;
                QHBoxLayout *HLayout = new QHBoxLayout;

                    QPixmap pix(":/Images/ImageDentists/ImageDentists/" + temp->at(i)->getPhoto());

                    QLabel *Icon = new QLabel;
                    QPushButton *detailed = new QPushButton(interface.object().value("Detailed").toString());
                    QPushButton *comments = new QPushButton(interface.object().value("Comments").toString());
                    detailed->setStyleSheet("color: black; background-color: rgb(199, 199, 199); font: 14pt;");
                    comments->setStyleSheet("color: black; background-color: rgb(199, 199, 199); font: 14pt;");
                try{
                    if (pix.isNull())
                    {
                        throw QString (":/Images/ImageDentists/ImageDentists/no-avatar.PNG");
                    }
                }
                catch(QString path){
                    MyException ex(pix, path);
                }

                Icon->setPixmap(pix.scaled(240,180));

                QLabel *Info = new QLabel;
                Icon->setAlignment(Qt::AlignRight);
                DentistInfo->setAlignment(Qt::AlignLeft);
                Info->setText(Info->text() + interface.object().value("FirstName").toString() + ": " + temp->at(i)->getFirstName() + "\n");
                Info->setText(Info->text() + interface.object().value("LastName").toString() + ": " + temp->at(i)->getLastName() + "\n");
                Info->setText(Info->text() + interface.object().value("Patronymic").toString() + ": " + temp->at(i)->getPatronymic() + "\n");
                Info->setText(Info->text() + interface.object().value("Specialization").toString() + ": " + temp->at(i)->getSpecialization() + "\n");
                Info->setText(Info->text() + interface.object().value("WorkExperience").toString() + ": " + QString::number(temp->at(i)->getWorkExperience()) + "\n");
                Info->setText(Info->text() + interface.object().value("ContactsDentist").toString() + ": " + temp->at(i)->getContactsDentist() + "\n");
                Info->setText(Info->text() + interface.object().value("Rating").toString() + ": " + QString::number(temp->at(i)->getRating()) + "\n");
                Info->setText(Info->text() + interface.object().value("NameOfDentistry").toString() + ": " + temp->at(i)->getDentistry().getNameOfDentistry());
                HLayout->addWidget(Icon);
                DentistInfo->addWidget(Info);
                QHBoxLayout *ButtonLayout = new QHBoxLayout();
                ButtonLayout->setAlignment(Qt::AlignLeft);
                ButtonLayout->addWidget(detailed);
                ButtonLayout->addWidget(comments);
                DentistInfo->addLayout(ButtonLayout);
                HLayout->addLayout(DentistInfo);
                Info->setMaximumHeight(220);
                VLayout->addLayout(HLayout);
                Dentist *tmp = temp->at(i);
                connect(detailed, &QPushButton::clicked, [this, tmp](){ this->SendDetailed(tmp); });
                connect(comments, &QPushButton::clicked, [this, tmp](){ this->SendComments(tmp); });
            }
    scrollAreaContent->setLayout(VLayout);
}

void MainWindow::SendDetailed(Dentist* temp){
    DetailedDentist *DD = new DetailedDentist();
    DD->sendDentist(temp, interface);
    DD->show();
}

void MainWindow::SendComments(Dentist* temp){
    CommentsDentist *cm = new CommentsDentist();
    cm->sendDentist(temp, interface);
    cm->show();
}
void MainWindow::on_actHelp_triggered()
{
    Help *t = new Help();
    t->SendSpecialization(&specialization, interface);
    t->show();
}

void MainWindow::on_actionEng_triggered()
{
    SaveDentist();
    QLabel *tmp = new QLabel();
    ui->scrollArea->setWidget(tmp);
    pathFileDentist = "../BotDetective-main/Date/dentist_eng.json";
    pathFileDentistry = "../BotDetective-main/Date/dentistry_eng.db";
    pathFileSpec = "../BotDetective-main/Date/spec_eng.json";
    pathInterface = "../BotDetective-main/Date/interface_eng.json";
    OpenInterface();
    OpenSpec();
    OpenDentistry();
    OpenDentist();
}

void MainWindow::on_actionUkr_triggered()
{
    SaveDentist();
    QLabel *tmp = new QLabel();
    ui->scrollArea->setWidget(tmp);
    pathFileDentist = "../BotDetective-main/Date/dentist_ukr.json";
    pathFileDentistry = "../BotDetective-main/Date/dentistry_ukr.db";
    pathFileSpec = "../BotDetective-main/Date/spec_ukr.json";
    pathInterface = "../BotDetective-main/Date/interface_ukr.json";
    OpenInterface();
    OpenSpec();
    OpenDentistry();
    OpenDentist();
}

void MainWindow::SaveDentist(){
    try{
        QFile fileDentist(pathFileDentist);
        if(!fileDentist.open(QIODevice::WriteOnly | QFile::Text)){
            throw 7;
        }
        else
        {
            QJsonDocument newDateDentist;
            for(int i = 0; i < listDentist.size(); i++){
            QVariantMap map;
            map.insert("firstName", listDentist.at(i)->getFirstName());
            map.insert("lastName", listDentist.at(i)->getLastName());
            map.insert("patronymic", listDentist.at(i)->getPatronymic());
            map.insert("years", listDentist.at(i)->getYears());
            map.insert("specialization", listDentist.at(i)->getSpecialization());
            map.insert("aboutDentist", listDentist.at(i)->getAboutDentist());
            map.insert("contactsDentis", listDentist.at(i)->getContactsDentist());
            map.insert("workExperience", listDentist.at(i)->getWorkExperience());
            map.insert("photo", listDentist.at(i)->getPhoto());
            map.insert("idOfDentistry", listDentist.at(i)->getIdOfDentistry());
            QVariantMap insideMap;
            QJsonArray commentsArray;
            for(int j = 0; j < listDentist.at(i)->getListComments().size(); j++){
                insideMap.clear();
                insideMap.insert("commentatorName", listDentist.at(i)->getListComments()[j].getCommentatorName());
                insideMap.insert("comment", listDentist.at(i)->getListComments()[j].getComment());
                insideMap.insert("rating", listDentist.at(i)->getListComments()[j].getRating());
                commentsArray.append(QJsonObject::fromVariantMap(insideMap));
            }
            map.insert("comments", commentsArray);
            QJsonObject json = QJsonObject::fromVariantMap(map);
            QJsonArray toWrite = newDateDentist.array();
            toWrite.append(json);
            newDateDentist.setArray(toWrite);
            }
            fileDentist.write("{\"Doctors\":" + newDateDentist.toJson()+"}");
        }
        fileDentist.close();
    }
    catch(int error){
        MyException ex(error, interface);
    }
}

void MainWindow::on_actDevelops_triggered()
{
    Developers *t = new Developers();
    t->SendInterface(interface);
    t->show();
}

void MainWindow::on_actionDentists_triggered()
{
    QList<Dentist*> temp;
    hashTableByName.searchAll(&temp);
    switch (ui->SortBy->currentIndex()) {
        case 0: sortByRating(&temp);
        break;
        case 1 : sortByAscending(&temp);
        break;
        case 2: sortByDescending(&temp);
        break;
    }
    ShowDentist(&temp);
}

void MainWindow::on_actionDentistry_triggered()
{
    QVBoxLayout *VLayout = new QVBoxLayout;
    QWidget* scrollAreaContent = new QWidget;
    ui->scrollArea->setWidget(scrollAreaContent);
            for(int i = 0; i < listDentistry.size();i++){
                QVBoxLayout *DentistryInfo = new QVBoxLayout;
                QPushButton *ShowDentistFromDentistry = new QPushButton(interface.object().value("ShowDentistFromDentistry").toString());
                ShowDentistFromDentistry->setStyleSheet("color: black; background-color: rgb(199, 199, 199); font: 14pt;");
                ShowDentistFromDentistry->setMaximumWidth(375);
                QTextBrowser *Info = new QTextBrowser;
                DentistryInfo->setAlignment(Qt::AlignCenter);
                Info->append(interface.object().value("NameOfDentistry").toString() + ": " + listDentistry.at(i)->getNameOfDentistry());
                Info->append( interface.object().value("WorkingHours").toString() + ": " + listDentistry.at(i)->getWorkingHours());
                Info->append(interface.object().value("Address").toString() + ": " + listDentistry.at(i)->getAddress());
                Info->append(interface.object().value("AboutUs").toString() + ": " + listDentistry.at(i)->getAboutUs());
                Info->append(interface.object().value("ContactsDentistry").toString() + ": " + listDentistry.at(i)->getContactsDentistry());
                Info->setFixedHeight(250);
                DentistryInfo->setContentsMargins(0,10,0,10);
                DentistryInfo->addWidget(Info);
                DentistryInfo->addWidget(ShowDentistFromDentistry);
                QString tmp = listDentistry.at(i)->getNameOfDentistry();
                connect(ShowDentistFromDentistry, &QPushButton::clicked, [this, tmp](){ this->SendShowDentistFromDentistry(tmp); });
                VLayout->addLayout(DentistryInfo);
         }
    scrollAreaContent->setLayout(VLayout);
}

void MainWindow::SendShowDentistFromDentistry(QString temp){
    SearchByDentistry(temp);
}

void MainWindow::on_actionSpecializations_triggered()
{
    QVBoxLayout *VLayout = new QVBoxLayout;
    QWidget* scrollAreaContent = new QWidget;
    ui->scrollArea->setWidget(scrollAreaContent);
            for(int i = 0; i < specialization.size();i++){
                QVBoxLayout *DentistryInfo = new QVBoxLayout;
                QPushButton *ShowDentistFromSpecialization = new QPushButton(interface.object().value("ShowDentistFromSpecialization").toString());
                ShowDentistFromSpecialization->setStyleSheet("color: black; background-color: rgb(199, 199, 199); font: 14pt;");
                ShowDentistFromSpecialization->setMaximumWidth(375);
                QTextBrowser *Info = new QTextBrowser;
                DentistryInfo->setAlignment(Qt::AlignCenter);
                Info->append(specialization.at(i).first);
                Info->setMaximumHeight(50);
                DentistryInfo->setContentsMargins(0,10,0,10);
                DentistryInfo->addWidget(Info);
                DentistryInfo->addWidget(ShowDentistFromSpecialization);
                QString tmp = specialization.at(i).first;
                connect(ShowDentistFromSpecialization, &QPushButton::clicked, [this, tmp](){ this->SendShowDentistFromSpecialization(tmp); });
                VLayout->addLayout(DentistryInfo);
         }
    scrollAreaContent->setLayout(VLayout);
}

void MainWindow::SendShowDentistFromSpecialization(QString temp){
    SearchBySpecialization(temp);
}

void MainWindow::on_actionClose_triggered()
{
    QApplication::quit();
}
