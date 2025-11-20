#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>
#include <QFile>
#include <QDebug>

class json_handler{
    public:
        enum MessageRole {System, User, Assistant};    

        // Initialization section
        json_handler();
        QJsonObject system_message_set(QString system_prompt) {
            system_message["role"] = "system";
            system_message["content"] = system_prompt;
            return system_message;
        }

        QJsonObject json_message_create(QString system_prompt, QString user_input);
        QJsonObject json_create_test();



        // Handle response
        QJsonObject json_get_message_from_response(QByteArray response_data){

            QJsonDocument doc = QJsonDocument::fromJson(response_data);
            auto obj = doc.object();
            auto choices = obj["choices"].toArray();
            
            // Extract assistant message
            QJsonObject assistant_message = choices.first()
                                                    .toObject()["message"]
                                                    .toObject();

            qDebug() << "Response received:" << response_data;

            return assistant_message;

        }

        
        // Save QJsonObject to a file
        int json_object_save(QJsonObject json_obj, QString file_path);
        int json_save_to_history(QJsonObject history_message);
        
    private:
        QJsonObject system_message;
        QJsonArray history_message;

        QJsonObject json_systmes_create(QString system_prompt = "You are a helpful assistant");
        QJsonObject json_usermes_create(QString user_input);
};

#endif // JSON_HANDLER_H
