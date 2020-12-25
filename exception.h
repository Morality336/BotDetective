#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QPixmap>

class MyException {
public:
    MyException(int error_code, QJsonDocument &interface);
    MyException(int error_code, QJsonDocument &interface, QString string_error);
    MyException(QPixmap &pix, QString path);
};

#endif // EXCEPTION_H
