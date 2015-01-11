#include "gtidirectoryscandialog.h"
#include "ui_gtidirectoryscandialog.h"
#include <QFileDialog>

GTIDirectoryScanDialog::GTIDirectoryScanDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GTIDirectoryScanDialog)
{
    ui->setupUi(this);

    connect(&directoryScanner, SIGNAL(tablatureCount(QString)), ui->label, SLOT(setText(QString)));
    connect(&directoryScanner, SIGNAL(tablatureFound(QString)),ui->labelMessage, SLOT(setText(QString)));
    connect(ui->btImportFile, SIGNAL(clicked()),SLOT(selectDirectory()));
    connect(&directoryScanner,SIGNAL(finished()),SLOT(finishedScaning()));
    connect(ui->btStart, SIGNAL(clicked()),SLOT(startscaner()));
}

GTIDirectoryScanDialog::~GTIDirectoryScanDialog()
{
    delete ui;
}

void GTIDirectoryScanDialog::startscaner()
{
    ui->btStart->setEnabled(false);
    ui->btImportFile->setEnabled(false);
    ui->buttonBox->setEnabled(false);
    directoryScanner.start();


}

void GTIDirectoryScanDialog::finishedScaning()
{
  ui->labelMessage->setText("Processing done !!");
  ui->btImportFile->setEnabled(true);
  ui->buttonBox->setEnabled(true);
}

void GTIDirectoryScanDialog::selectDirectory()
{
    QString directory = QFileDialog::getExistingDirectory(this, "Select root directory to scan");
    if (directory.isNull() || directory.isEmpty()) {
        return;
    }
    directoryScanner.setRootDirectory(directory);
    ui->lineEditDirectoryName->setText(directory);
    ui->btStart->setEnabled(true);
}
