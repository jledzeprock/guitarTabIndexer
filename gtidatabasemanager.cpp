#include "gtidatabasemanager.h"
#include <QDir>
#include <QStandardPaths>

GTIDataBaseManager::GTIDataBaseManager(QObject *parent) : QObject(parent), m_filePath(QDir::homePath())
{

}

bool GTIDataBaseManager::openDB() {
    if (db.isOpen()) {
        return true;
    }
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");
#ifdef Q_OS_MAC   // OSX
    // We have to Store database into user Documents folder
    m_filePath.append(QDir::separator()).append("Documents").append(QDir::separator()).append("GuitarTabIndexer");
#elif __linux__ // UNIX
    // We have to Store database into user home folder
    m_filePath.append(QDir::separator()).append(".GuitarTabIndexer");
#elif _WIN32 // WINDOWS
    // We have to Store database into user home folder
    m_filePath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
#endif
    m_filePath = QDir::toNativeSeparators(m_filePath);
    QDir appDir(m_filePath);
    if (!appDir.exists()) {
        appDir.mkdir(m_filePath);
    }
    m_filePath.append(QDir::separator()).append("GuitarTabIndexer.sqlite");
    m_filePath = QDir::toNativeSeparators(m_filePath);
    db.setDatabaseName(m_filePath);
    return db.open();
}

bool GTIDataBaseManager::deleteDB() {
    if (!closeDB()) {
        return false;
    }
    return QFile::remove(m_filePath);
}

QSqlError GTIDataBaseManager::lastError() {
    return db.lastError();
}

QSqlDatabase GTIDataBaseManager::getDataBase()
{
    return db;
}

bool GTIDataBaseManager::closeDB() {
    if ( db.isOpen()) {
        db.close();
        return true;
    }
    return true;
}
GTIDataBaseManager::~GTIDataBaseManager()
{
    closeDB();
}

