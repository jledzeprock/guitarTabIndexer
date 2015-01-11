#ifndef GUITARTAB_H
#define GUITARTAB_H

#include <QObject>
#include <QString>

class GuitarTab
{
public:
    explicit GuitarTab();
    GuitarTab(const GuitarTab & another);
    ~GuitarTab();
    QString getBandName() const;
    QString getSongTitle() const;
    QString getTabPath() const;
    QString getSummary() const;
    QString getExtension() const;
    void setExtension(QString value);
    void setBandName(QString value);
    void setSongTitle(QString value);
    void setTabPath(QString value);
    void setSummary(QString desc);
    void initSummary();
private:
    QString bandName, songTitle, tabPath, summary, extension;
};

#endif // GUITARTAB_H
