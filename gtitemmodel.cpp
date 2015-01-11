#include "gtitemmodel.h"



GTItemModel::GTItemModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int GTItemModel::rowCount(const QModelIndex &parent) const
{
    return myList.size();
}

int GTItemModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant GTItemModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int column = index.column();

    switch (role) {
    case Qt::DisplayRole:

        switch (column) {
        case 0:
            return (myList.at(row).getExtension());
            break;
        case 1:
            return (myList.at(row).getSummary());
            break;
        case 2:
            return (myList.at(row).getTabPath());
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return QVariant();
}

QVariant GTItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
   if (orientation == Qt::Vertical) {
        return QVariant();
   }

    switch (role) {
    case Qt::DisplayRole:
        switch (section) {
        case 0:
                return "Format";
        case 1:
               return "Band - Song Tile";
            break;
        }
        break;
    }
    return QVariant();
}

QString GTItemModel::getTabPath(int row)
{
    return myList.at(row).getTabPath();
}

void GTItemModel::setGuitarTabList(QList<GuitarTab> &tabs) {
    this->myList = tabs;
    QModelIndex top = createIndex(0,0), bottom = createIndex(myList.size(),1);
    emit dataChanged(top,bottom);
    emit layoutChanged();

}
