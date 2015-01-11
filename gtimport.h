#ifndef GTIMPORT_H
#define GTIMPORT_H

#include <QDialog>
#include "guitartab.h"

namespace Ui {
class GTImport;
}

class GTImport : public QDialog
{
    Q_OBJECT

public:
    explicit GTImport(QWidget *parent = 0);
    ~GTImport();
    GuitarTab getGuitarTab();
    void setGuitarTab(GuitarTab guitarTab);
public slots:
    void importFile();
    void accept();
private:
    void initTabGui();
    Ui::GTImport *ui;
    GuitarTab m_tab;
};

#endif // GTIMPORT_H
