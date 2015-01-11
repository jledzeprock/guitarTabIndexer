#ifndef GTITABUTIL_H
#define GTITABUTIL_H

#include "guitartab.h"
#include <QString>
#include <QFile>
#include <QDir>


class GTITabUtil
{
public:
    static GuitarTab getGuitarTab(QString & path);
    static void openGuitarTab(GuitarTab & guitarTab);
    static void openGuitarTab(QString & guitarTab);
    static GuitarTab getGuitarTab(QFileInfo & info);
    GTITabUtil();
    ~GTITabUtil();
};

#endif // GTITABUTIL_H
