#ifndef GTI_DATABASE_MANAGER_H
#define GTI_DATABASE_MANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>

class GTIDataBaseManager : public QObject
{
    Q_OBJECT
public:
    explicit GTIDataBaseManager(QObject *parent = 0);
    ~GTIDataBaseManager();
    bool openDB();
    bool deleteDB();
    bool closeDB();
    QSqlError lastError();
    QSqlDatabase getDataBase();
private:
    bool m_opened;
    QString  m_filePath;
    QSqlDatabase db;

signals:

public slots:
};

#endif // GTI_DATABASE_MANAGER_H
