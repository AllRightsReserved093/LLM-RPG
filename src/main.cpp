#include "mainwindow.h"
#include "deepseek_api_services.h"

#include <iostream>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
