#-------------------------------------------------
#
# Project created by QtCreator 2015-01-02T21:30:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GuitarTabIndexer
TEMPLATE = app

ICON = icon.jpeg

SOURCES += main.cpp\
        mainwindow.cpp \
    guitartab.cpp \
    gtidatabasemanager.cpp \
    gtidao.cpp \
    gtimport.cpp \
    gtitabutil.cpp \
    gtidirectoryscanner.cpp \
    gtidirectoryscandialog.cpp \
    gtitemmodel.cpp

HEADERS  += mainwindow.h \
    guitartab.h \
    gtidatabasemanager.h \
    gtidao.h \
    gtimport.h \
    gtitabutil.h \
    gtidirectoryscanner.h \
    gtidirectoryscandialog.h \
    gtitemmodel.h

FORMS    += mainwindow.ui \
    gtimport.ui \
    gtidirectoryscandialog.ui

RESOURCES += \
    tabindexerres.qrc
