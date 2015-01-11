#ifndef GTIDIRECTORYSCANNER_H
#define GTIDIRECTORYSCANNER_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QList>
#include "guitartab.h"
#include <QDir>

class GTIDirectoryScanner : public QThread
{
    Q_OBJECT
public:
    explicit GTIDirectoryScanner(QObject * parent = 0);
    void setRootDirectory(QString root);
    ~GTIDirectoryScanner();
protected:
    void run();
 signals:
    void tablatureFound(QString name);
    void tablatureCount(QString count);
    void tablatureChunck(QList<GuitarTab> tabs);
private:
    int scanRec(QDir dir, int cpt);
    QString rootDirectory;
};

#endif // GTIDIRECTORYSCANNER_H
