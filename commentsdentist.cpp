#include "commentsdentist.h"
#include "ui_commentsdentist.h"
#include "dentist.h"
#include "QBoxLayout"
#include "QTextBrowser"
#include <QMessageBox>
#include <QDoubleSpinBox>

CommentsDentist::CommentsDentist(QWidget *parent) :QWidget(parent),ui(new Ui::CommentsDentist)
{    
    ui->setupUi(this);
}

CommentsDentist::~CommentsDentist()
{
    delete ui;
}

void CommentsDentist::sendDentist(Dentist *temp, QJsonDocument &interface){
    this->interface = interface;
    this->currentDentist = temp;
    QPixmap pix(":/Images/ImageDentists/ImageDentists/" + currentDentist->getPhoto());
    if (pix.isNull())
    {
       QPixmap noAvatarPix(":/Images/ImageDentists/ImageDentists/no-avatar.PNG");
       ui->Photo->setPixmap(noAvatarPix.scaled(240,180));
    }
    else
    {
        ui->Photo->setPixmap(pix.scaled(240, 180));
    }
    ui->FirstName->setText(interface.object().value("FirstName").toString() + ": " + currentDentist->getFirstName());
    ui->LastName->setText(interface.object().value("LastName").toString() + ": " + currentDentist->getLastName());
    ui->Patronymic->setText(interface.object().value("Patronymic").toString() + ": " + currentDentist->getPatronymic());
    ui->Specialization->setText(interface.object().value("Specialization").toString() + ": " + currentDentist->getSpecialization());
    ui->AddCommentBtn->setText(interface.object().value("AddCommentBtn").toString());
    ui->CommentLabel->setText(interface.object().value("CommentLabel").toString());
    ui->CommentatorNameLabel->setText(interface.object().value("CommentatorNameLabel").toString());
    ui->RatingLabel->setText(interface.object().value("Rating").toString() + " ([0,5])");
    addComment();
}

void CommentsDentist::addComment(){
    QVBoxLayout *mainLayout = new QVBoxLayout();
    if (currentDentist->getListComments().size() == 0)
    {
        QPixmap pix(":/Images/ImageDentists/ImageDentists/Uncle Sam.jpg");
        QLabel* photoUncleSam = new QLabel;
        photoUncleSam->setPixmap(pix.scaled(522, 293));
        QLabel* nullComments = new QLabel(interface.object().value("NullComments").toString());
        mainLayout->addWidget(photoUncleSam);
        mainLayout->addWidget(nullComments);
    }
    else{
        for (int i = 0; i < currentDentist->getListComments().size(); i++){
            QVBoxLayout *tmpLayout = new QVBoxLayout();
            tmpLayout->setAlignment(Qt::AlignLeft);
            QTextBrowser *LabelCommentatorName = new QTextBrowser();
            LabelCommentatorName->setText(currentDentist->getListComments()[i].getCommentatorName());
            LabelCommentatorName->setMaximumHeight(35);
            tmpLayout->addWidget(LabelCommentatorName);
            QTextBrowser *LabelComment = new QTextBrowser();
            LabelComment->setText(currentDentist->getListComments()[i].getComment());
            LabelComment->setMaximumHeight(75);
            tmpLayout->addWidget(LabelComment);
            QTextBrowser *LabelRating = new QTextBrowser();
            LabelRating->setText(QString::number(currentDentist->getListComments()[i].getRating()));
            LabelRating->setMaximumHeight(35);
            tmpLayout->addWidget(LabelRating);
            tmpLayout->setContentsMargins(0,10,0,10);
            mainLayout->addLayout(tmpLayout);
        }
    }
    QWidget *wd = new QWidget();
    wd->setLayout(mainLayout);
    ui->scrollArea->setWidget(wd);
}
void CommentsDentist::countRating(){
    double Rating = 0;
    for(int i = 0; i < currentDentist->getListComments().size(); i++){
        Rating += currentDentist->getListComments()[i].getRating();
    }
    currentDentist->setRating(Rating / currentDentist->getListComments().size());
}
void CommentsDentist::on_AddCommentBtn_clicked()
{

    if( ui->Rating->text() == "" || ui->Rating->text().at(0).unicode() < 48 || ui->Rating->text().at(0).unicode() > 53 ||  (ui->Rating->text().at(0).unicode() == 53 && ui->Rating->text().size() != 1))
    {
        QMessageBox::warning(0, interface.object().value("Error").toString(),interface.object().value("ErrorRating").toString());
    }
    else if (ui->CommentatorName->text() == "")
    {
        QMessageBox::warning(0, interface.object().value("Error").toString(),interface.object().value("ErrorCommentatorName").toString());
    }
    else{
        Comments *temp = new Comments();
        temp->setCommentatorName(ui->CommentatorName->text());
        temp->setComment(ui->Comment->text());
        temp->setRating(ui->Rating->text().toDouble());
        ui->CommentatorName->clear();
        ui->Comment->clear();
        ui->Rating->clear();
        currentDentist->addListComments(*temp);
        addComment();
        countRating();
        QMessageBox::information(0, interface.object().value("Success").toString(),interface.object().value("SuccessAddComment").toString());
    }
}
