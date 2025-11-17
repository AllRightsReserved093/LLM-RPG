#ifndef DEEPSEEK_API_SERVICES_H
#define DEEPSEEK_API_SERVICES_H

#include "json_handler.h"
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

        int deepseek_api_call();
    private:
        QByteArray apiKey;

        QJsonObject deepseek_api_call_perpare();
        QNetworkAccessManager *manager = nullptr;
        int deepseek_api_request();
        int deepseek_api_response();

        void onReplyFinished(QNetworkReply* reply);
    };

#endif // DEEPSEEK_API_SERVICES_H
