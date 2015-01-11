#ifndef GTITEMMODEL_H
#define GTITEMMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "guitartab.h"


class GTItemModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    GTItemModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void setGuitarTabList(QList<GuitarTab> & tabs);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QString getTabPath(int row);
private:
    QList<GuitarTab> myList;
};

#endif // GTITEMMODEL_H
