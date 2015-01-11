#include "gtimport.h"
#include "ui_gtimport.h"
#include <QFileDialog>
#include "gtitabutil.h"

GTImport::GTImport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GTImport)
{
    ui->setupUi(this);
    connect(ui->btImportFile, SIGNAL(clicked()),SLOT(importFile()));
}

GTImport::~GTImport()
{
    delete ui;
}

GuitarTab GTImport::getGuitarTab()
{
    return m_tab;
}

void GTImport::setGuitarTab(GuitarTab guitarTab)
{
    m_tab = guitarTab;
    initTabGui();
}

void GTImport::importFile()
{
    QString file = QFileDialog::getOpenFileName(this, "Select File",QDir::homePath(), "*.gp*");
    if (!file.isNull() && ! file.isEmpty()) {
        m_tab = GTITabUtil::getGuitarTab(file);
        initTabGui();
    }
}

void GTImport::accept() {
    if (ui->lineEditFileName->text().isEmpty()) {
        return;
    }
    m_tab.setBandName(ui->lineEditBandName->text());
    m_tab.setSongTitle(ui->lineEditSongName->text());
    m_tab.setTabPath(ui->lineEditFileName->text());
    m_tab.initSummary();
    QDialog::accept();
}

void GTImport::initTabGui() {
    ui->lineEditBandName->setText(m_tab.getBandName());
    ui->lineEditFileName->setText(m_tab.getTabPath());
    ui->lineEditSongName->setText(m_tab.getSongTitle());
}
