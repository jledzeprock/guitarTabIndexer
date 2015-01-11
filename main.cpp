#include "mainwindow.h"
#include <QApplication>
#include <QSqlError>
#include <iostream>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;
    w.show();


    return a.exec();
    //    } catch (QSqlError error) {
    //        std::cout<< "Error Occured : database message"<< error.databaseText().toStdString() << std::endl;
    //        std::cout<< "Error Occured : driver message"<< error.driverText().toStdString() << std::endl;
    //    }

}
