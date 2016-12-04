#-------------------------------------------------
#
# Project created by QtCreator 2016-10-16T08:22:26
#
#-------------------------------------------------

QT += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Homework
TEMPLATE = app

#LIBS += -L/usr/local/Cellar/qca/2.1.1/lib/qca-qt5.framework/Versions/2.1.1/ -lQtCrypto
#INCLUDEPATH += /usr/local/Cellar/qca/2.1.1/lib/qca-qt5.framework/Versions/2.1.1/Headers/QtCrypto
#CONFIG += crypto

SOURCES += main.cpp\
        mainwindow.cpp \
    reg.cpp \
    maincontent.cpp \
    database.cpp \
    crypt.cpp

HEADERS  += mainwindow.h \
    reg.h \
    maincontent.h \
    database.h \
    crypt.h

FORMS    += mainwindow.ui \
    reg.ui \
    maincontent.ui \
    database.ui
LIBS += /usr/local/lib/libbotan-1.11.33.33.dylib

maxc:ICON += /Users/nikitakurganov/Documents/Qt/SecureStorage/securestorage.icns


