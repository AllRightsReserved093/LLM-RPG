#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>

class json_handler{
    public:
        
        json_handler();
        QJsonObject json_message_create(QString user_input);
        QJsonObject json_create_test();
        
        void system_message_set(QString new_system_content) {
            system_prompt = new_system_content;
        }
    private:
        QString system_prompt = "You are a helpful assistant";
        QJsonObject json_systmes_create();
        QJsonObject json_usermes_create(QString user_input);
};

#endif // JSON_HANDLER_H
