#include "gtitabutil.h"
#include <QFileInfo>
#include <QDesktopServices>
#include <QUrl>
#include <iostream>

GuitarTab GTITabUtil::getGuitarTab(QString &path)
{

    QFile file(path);
    if (!file.exists()) {
        return GuitarTab();
    }
    QFileInfo info(file);
    return getGuitarTab(info);
}
GuitarTab GTITabUtil::getGuitarTab(QFileInfo & info)
{
    GuitarTab tab;
     tab.setTabPath(info.absoluteFilePath());
     tab.setExtension(info.suffix());
    QString name = info.baseName();
    tab.setSummary(name);
    if (name.contains("-")) {
        QStringList list = name.split("-");
        tab.setBandName(list.at(0));
        tab.setSongTitle(list.at(1));
    } else {
        tab.setBandName(name);
        tab.setSongTitle(name);
    }
    return tab;
}

void GTITabUtil::openGuitarTab(GuitarTab &guitarTab)
{
    QString path = guitarTab.getTabPath();
   openGuitarTab(path);
}

void GTITabUtil::openGuitarTab(QString & guitarTab)
{
    std::cout<< "Traying to open file: "<< guitarTab.toStdString() << std::endl;
    QUrl url;
    url.setPath(guitarTab);
    url.setScheme("file");
    int result = QDesktopServices::openUrl(url);
    std::cout<< "QDesktopServices::openUrl: "<< result << std::endl;
}

GTITabUtil::GTITabUtil()
{

}

GTITabUtil::~GTITabUtil()
{

}

