QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commentsdentist.cpp \
    dentist.cpp \
    dentistry.cpp \
    detaileddentist.cpp \
    developers.cpp \
    exception.cpp \
    hashtablebyname.cpp \
    hashtablebynameofdentistry.cpp \
    hashtablebyspecialization.cpp \
    help.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    commentsdentist.h \
    dentist.h \
    dentistry.h \
    detaileddentist.h \
    developers.h \
    exception.h \
    hashtablebyname.h \
    hashtablebynameofdentistry.h \
    hashtablebyspecialization.h \
    help.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

FORMS += \
    commentsdentist.ui \
    detaileddentist.ui \
    developers.ui \
    help.ui \
    mainwindow.ui

DISTFILES += \
    BotDetective.pro.user
