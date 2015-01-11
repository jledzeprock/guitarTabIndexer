#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <iostream>
#include "gtitabutil.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),importSingleDialog(this), scanerDialog(this), itemsModel(this)
{
    ui->setupUi(this);
    connect(this->ui->actionImport_Library, SIGNAL(triggered()), &importSingleDialog, SLOT(open()));
    connect(&importSingleDialog, SIGNAL(accepted()), SLOT(saveRecord()));
    connect(ui->lineEdit, SIGNAL(returnPressed()), SLOT(applySearch()));
//    connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), SLOT(onRowSelected(QModelIndex)));
    connect(ui->tableView, SIGNAL(activated(QModelIndex)), SLOT(onRowSelected(QModelIndex)));
    connect(ui->actionScan_directory, SIGNAL(triggered()), SLOT(scanDirectory()));
    connect(&scanerDialog, SIGNAL(accepted()),SLOT(reloadData()));
    initCompletion();
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete sqlModel;
    //delete proxy_model;
}


void MainWindow::scanDirectory()
{
    scanerDialog.show();
}

void MainWindow::saveRecord()
{
    std::cout<< "Dialog Import Accepted" << std::endl;
    QList<GuitarTab> tabList;
    GuitarTab tab = importSingleDialog.getGuitarTab();
    tabList.append(tab);
    dtiDao.saveRecords(tabList);
}

void MainWindow::applySearch()
{
    QString terms = ui->lineEdit->text();
    if (terms.isNull() || terms.isEmpty()) {
        // proxy_model->setFilterRegExp("");
    } else {
        if (!terms.contains('%')) {
            terms = "%"+ terms +"%";
        }
        QList<GuitarTab> tabs= dtiDao.search(terms);
        itemsModel.setGuitarTabList(tabs);
        ui->tableView->setFocus();
      // proxy_model->setFilterRegExp(terms);
    }
}

void MainWindow::onRowSelected(QModelIndex index)
{
    int row = index.row();
    std::cout << "Row selected :"<< row << std::endl;
    QString path = itemsModel.getTabPath(row);
    if (!path.isEmpty()) {
        GTITabUtil::openGuitarTab(path);
    } else {
        QMessageBox::warning(this, "Invalid Path", "Error while trying to open tab");
    }

}

void MainWindow::reloadData()
{
    //sqlModel->select();
}

void MainWindow::initCompletion()
{
//    this->sqlModel = new  QSqlTableModel();
    //proxy_model = new QSortFilterProxyModel();
//    sqlModel->setTable("GuitarTab");
//    sqlModel->select();

//    completer.setModel(sqlModel);
//    completer.setCompletionMode(QCompleter::PopupCompletion);
//    completer.setCaseSensitivity(Qt::CaseInsensitive);
//    completer.setFilterMode(Qt::MatchContains);
//    completer.setCompletionColumn(2);
//    ui->lineEdit->setCompleter(&completer);
//    proxy_model->setSourceModel(sqlModel);
//    proxy_model->setFilterKeyColumn(2);
//    proxy_model->setFilterCaseSensitivity(Qt::CaseInsensitive);

    // config table view
    ui->tableView->setModel(&itemsModel);
    //ui->tableView->setColumnHidden(0, true);
   // ui->tableView->setColumnHidden(2, true);
}
