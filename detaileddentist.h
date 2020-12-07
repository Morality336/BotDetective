#ifndef DETAILEDDENTIST_H
#define DETAILEDDENTIST_H

#include <QWidget>
#include "dentist.h"
#include "dentistry.h"
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
namespace Ui {
class DetailedDentist;
}

class DetailedDentist : public QWidget
{
    Q_OBJECT

public:
    explicit DetailedDentist(QWidget *parent = nullptr);
    ~DetailedDentist();
    void sendDentist(Dentist* temp, QJsonDocument &interface);

private:
    Ui::DetailedDentist *ui;
};

#endif // DETAILEDDENTIST_H
