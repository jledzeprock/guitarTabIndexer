#ifndef GTIDIRECTORYSCANDIALOG_H
#define GTIDIRECTORYSCANDIALOG_H

#include <QDialog>
#include "gtidirectoryscanner.h"

namespace Ui {
class GTIDirectoryScanDialog;
}

class GTIDirectoryScanDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GTIDirectoryScanDialog(QWidget *parent = 0);
    ~GTIDirectoryScanDialog();
public slots:
    void startscaner();
    void finishedScaning();
    void selectDirectory();
private:
    Ui::GTIDirectoryScanDialog *ui;
    GTIDirectoryScanner directoryScanner;
};

#endif // GTIDIRECTORYSCANDIALOG_H
