#include "gtidirectoryscanner.h"
#include <QDir>
#include <iostream>
#include "gtidao.h"
#include "gtitabutil.h"


GTIDirectoryScanner::GTIDirectoryScanner(QObject * parent) : QThread(parent)
{

}

void GTIDirectoryScanner::setRootDirectory(QString root)
{
    this->rootDirectory = root;
}

GTIDirectoryScanner::~GTIDirectoryScanner()
{

}

void GTIDirectoryScanner::run()
{
    QDir rootDir(rootDirectory);
    if (!rootDir.exists()) {
        return;
    }
    scanRec(rootDir, 0);
}

int GTIDirectoryScanner::scanRec(QDir dir, int cpt)
{
    QStringList files = dir.entryList(QDir::Files | QDir::Readable);
    int count = cpt;
    QString fullFilePath;
    QList<GuitarTab> tabs;
    foreach (QString file, files) {
        fullFilePath = dir.filePath(file);
        QFileInfo info(fullFilePath);
        if (info.suffix().startsWith("gp", Qt::CaseInsensitive)) {
            emit tablatureFound("Processing: "+ fullFilePath);
            count++;
            emit tablatureCount(QString::number(count));
            GuitarTab tab = GTITabUtil::getGuitarTab(info);
            tabs.push_back(tab);
        }
    }

    if (!tabs.isEmpty()) {
        GTIDao::getInstance()->saveRecords(tabs);
    }
    QStringList dirs = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Readable);
    foreach (QString currentDir, dirs) {

        QDir cDir(dir.absoluteFilePath(currentDir));
        std::cout<<"Processing dir: " << currentDir.toStdString() <<std::endl;
        count += scanRec(cDir, count);
    }
    return count;
}

