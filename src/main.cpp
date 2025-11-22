#include "windows/mainwindow.h"

#include "deepseek_api_services.h"
#include "json_message_handler.h"

#include <iostream>

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.show();
    return a.exec();
    // return 0;
}
