#include "gtidao.h"
#include<QStringList>
#include<QSqlQuery>
#include<iostream>
#include<QSqlRecord>
#include<QVariant>

GTIDao * GTIDao::instance = NULL;
GTIDao::GTIDao(): dbManager()
{
    if (dbManager.openDB()) {

        QStringList tables = dbManager.getDataBase().tables(QSql::AllTables);
        if (!tables.contains("GuitarTab")) {
           QSqlQuery query = dbManager.getDataBase().exec("CREATE TABLE GuitarTab (path varchar(300) primary key, "
                                                          "bandName varchar(100) default 'Unknown', "
                                                          "summary varchar(200), "
                                                          "songName varchar(100) default 'Unknown', "
                                                          "extension varchar(10),"
                                                          "created timestamp default CURRENT_TIMESTAMP);");
         QSqlError error = query.lastError();
         if (error.isValid()) {
             std::cout<< "Error Occured, Database text: "<< error.databaseText().toStdString() << std::endl;
             std::cout<< "Error Occured, Driver text: "<< error.driverText().toStdString() << std::endl;
         }

        }
    } else {
        throw dbManager.lastError();
    }
    instance = this;
}

GTIDao::~GTIDao()
{
    dbManager.closeDB();
}

QList<GuitarTab> GTIDao::search(QString terms) {
    std::cout<<"Making search for term: "<< terms.toStdString() << std::endl;
    QSqlQuery query;
    query.prepare("SELECT * from GuitarTab where summary LIKE :term");
    query.bindValue(":term", QVariant(terms));
    query.exec();
    QSqlRecord record = query.record();
    int pathIndex = record.indexOf("path");
    int bandNameIndex = record.indexOf("bandName");
    int songNameIndex = record.indexOf("songName");
    int summaryIndex = record.indexOf("summary");
    int extensionIndex = record.indexOf("extension");
    QList<GuitarTab> tabs;
    while (query.next()) {
        GuitarTab tab;
        tab.setBandName(query.value(bandNameIndex).toString());
        tab.setSongTitle(query.value(songNameIndex).toString());
        tab.setTabPath(query.value(pathIndex).toString());
        tab.setSummary(query.value(summaryIndex).toString());
        tab.setExtension(query.value(extensionIndex).toString());
        tabs.append(tab);
    }
    std::cout << "Result found count: " << tabs.size() << " for search term: " << terms.toStdString()<< std::endl;
    return tabs;
}

void GTIDao::saveRecords(QList<GuitarTab> &tabs)
{
    QList<GuitarTab>::Iterator it = tabs.begin(), end = tabs.end();
     for (; it != end; it++) {
        QSqlQuery query;
        query.prepare("INSERT INTO GuitarTab (path, bandName, songName, summary, extension) VALUES(:path, :band, :song, :summary, :ext)");
        query.bindValue(":path", it->getTabPath());
        query.bindValue(":band", it->getBandName());
        query.bindValue(":song", it->getSongTitle());
        query.bindValue(":summary", it->getSummary());
        query.bindValue(":ext", it->getExtension());
        query.exec();

     }
}

GTIDao *GTIDao::getInstance()
{
    return instance;
}
