#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gtidao.h"
#include "gtimport.h"
#include <QCompleter>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include "gtidirectoryscandialog.h"
#include "gtitemmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void scanDirectory();
    void saveRecord();
    void applySearch();
    void onRowSelected(QModelIndex index);
    void reloadData();
private:
    void initCompletion();
    Ui::MainWindow *ui;
    GTIDao dtiDao;
    GTImport importSingleDialog;
    QSqlTableModel * sqlModel;
    QCompleter completer;
    QSortFilterProxyModel * proxy_model;
    GTIDirectoryScanDialog scanerDialog;
    GTItemModel itemsModel;
};

#endif // MAINWINDOW_H
