#include <exception.h>
#include <QMessageBox>

MyException::MyException(int error_code, QJsonDocument &interface){
    switch(error_code){
    case 1:   //пользователь не ввёл данные в диалоговую строку
        QMessageBox::warning(0, interface.object().value("Error").toString(), interface.object().value("EmptyLine").toString());
        break;
    case 2:  //пользователь ввёл несуществующий рейтинг
        QMessageBox::warning(0, interface.object().value("Error").toString(),interface.object().value("ErrorRating").toString());
        break;
    case 3:  //пользователь не ввёл рейтинг
        QMessageBox::warning(0, interface.object().value("Error").toString(),interface.object().value("ErrorCommentatorName").toString());
        break;
    case 4:   //не открывается файл со специализациями
        QMessageBox::warning(0, interface.object().value("FailOpen").toString(), interface.object().value("FailOpenSpec").toString());
        break;
    case 5:   //не открывается файл с докторами
        QMessageBox::warning(0, interface.object().value("FailOpen").toString(), interface.object().value("FailOpenDoctors").toString());
        break;
    case 6:   //не открывается файл со стоматологиями
        QMessageBox::warning(0, interface.object().value("FailOpen").toString(), interface.object().value("FailOpenDentistry").toString());
        break;
    case 7:   //не открывается файл с данными интерфейса: для чтения, для записи
        QMessageBox::warning(0, interface.object().value("FailOpen").toString(), interface.object().value("FailOpenInterface").toString());
        break;
    default:
        break;
    }
};

MyException::MyException(int error_code, QJsonDocument &interface, QString string_error){
    switch(error_code){
    case 1:   //не найдена фамилия
        QMessageBox::warning(0, interface.object().value("NotFound").toString(), interface.object().value("NotFoundName").toString() + string_error + "!");
        break;
    case 2:   //не найдена специализация
        QMessageBox::warning(0, interface.object().value("NotFound").toString(), interface.object().value("NotFoundSpec").toString() + string_error + "!");
        break;
    case 3:   //не найдена стоматология
        QMessageBox::warning(0, interface.object().value("NotFound").toString(), interface.object().value("NotFoundDentistry").toString() + string_error + "!");
        break;
    default:
        break;
    }
};

MyException::MyException(QPixmap &pix, QString path){    //не была найдено нужная картинка, поэтому заменена на стандартную
    pix.load(path);
};
