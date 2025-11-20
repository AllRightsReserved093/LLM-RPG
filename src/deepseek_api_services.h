#ifndef DEEPSEEK_API_SERVICES_H
#define DEEPSEEK_API_SERVICES_H

#include "json_message_handler.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtGlobal>
#include <QByteArray>


using namespace std;
    
class deepseek_api_services : public QObject {
    public:
        deepseek_api_services();
        ~deepseek_api_services();

        // Use the provided json_handler instance for JSON operations
        int deepseek_api_json_object(json_handler user_json_handler_instance) {
            json_handler_instance = user_json_handler_instance;
            return 0;
        }

        int deepseek_api_call(QJsonObject message);
    private:
        // Store the API key
        QByteArray apiKey;
        json_handler json_handler_instance;

        QNetworkAccessManager *manager = nullptr;

        int deepseek_api_request();
        int deepseek_api_response();

        void onReplyFinished(QNetworkReply* reply);
    };

#endif // DEEPSEEK_API_SERVICES_H
