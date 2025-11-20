#include "mainwindow.h"

#include "deepseek_api_services.h"
#include "json_message_handler.h"

#include <iostream>

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    json_handler json_handler_instance;

    json_handler_instance.system_message_set("使用中文回答");
    
    QJsonObject test_json = json_handler_instance.json_message_create("empty", "Hello");

    std::cout << QJsonDocument(test_json).toJson(QJsonDocument::Compact).toStdString() << std::endl;

    deepseek_api_services api_service;
    api_service.deepseek_api_call(test_json);

    int temp;
    cout << "Pressed Enter to exit..." << endl;
    cin >> temp;

    // w.show();
    // return a.exec();
    return 0;
}
