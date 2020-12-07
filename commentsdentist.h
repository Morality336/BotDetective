#ifndef COMMENTSDENTIST_H
#define COMMENTSDENTIST_H

#include <QWidget>
#include "dentist.h"
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "dentist.h"

namespace Ui {
class CommentsDentist;
}

class CommentsDentist : public QWidget
{
    Q_OBJECT

public:
    explicit CommentsDentist(QWidget *parent = nullptr);
    ~CommentsDentist();
     void sendDentist(Dentist *temp, QJsonDocument &interface);
     void addComment();
     void countRating();

private slots:
     void on_AddCommentBtn_clicked();

private:
    Ui::CommentsDentist *ui;
    QJsonDocument interface;
    Dentist *currentDentist;
};

#endif // COMMENTSDENTIST_H
