#-------------------------------------------------
#
# Project created by QtCreator 2016-10-16T08:22:26
#
#-------------------------------------------------

QT += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Homework
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    reg.cpp \
    maincontent.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    reg.h \
    maincontent.h \
    database.h

FORMS    += mainwindow.ui \
    reg.ui \
    maincontent.ui \
    database.ui

RESOURCES +=
