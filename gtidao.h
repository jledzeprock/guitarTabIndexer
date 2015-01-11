#ifndef GTIDAO_H
#define GTIDAO_H
#include <QList>
#include "gtidatabasemanager.h"
#include "guitartab.h"


class GTIDao
{
public:
    GTIDao();
    ~GTIDao();
    QList<GuitarTab>  search(QString terms);
    void saveRecords(QList<GuitarTab> & tabs);
    static GTIDao * getInstance();
private:
  int execQuery(const char * query);
  GTIDataBaseManager dbManager;
  static GTIDao * instance;

};

#endif // GTIDAO_H
