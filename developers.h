#ifndef DEVELOPERS_H
#define DEVELOPERS_H

#include <QWidget>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
namespace Ui {
class Developers;
}

class Developers : public QWidget
{
    Q_OBJECT

public:
    explicit Developers(QWidget *parent = nullptr);
    ~Developers();
    void SendInterface(QJsonDocument &interface);

private:
    Ui::Developers *ui;
};

#endif // DEVELOPERS_H
