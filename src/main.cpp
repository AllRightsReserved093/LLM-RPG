#include "mainwindow.h"

#include "deepseek_api_services.h"
#include "json_handler.h"

#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    json_handler json_handler_instance;
    QJsonObject test_json = json_handler_instance.json_create_test();
    std::cout << QJsonDocument(test_json).toJson(QJsonDocument::Compact).toStdString() << std::endl;

    deepseek_api_services api_service;
    api_service.deepseek_api_call();

    // w.show();
    return a.exec();
}
