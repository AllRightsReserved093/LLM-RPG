#ifndef DEEPSEEK_API_SERVICES_H
#define DEEPSEEK_API_SERVICES_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QtGlobal>
#include <QByteArray>

#include <iostream>



using namespace std;
    
class deepseek_api_services : public QObject {
    Q_OBJECT

    public:
        deepseek_api_services();
        ~deepseek_api_services();

        int deepseek_api_call(QJsonObject message);
    
    signals:
        void replyReady(const QByteArray replyContent);

    private:
        // Store the API key
        QByteArray apiKey;

        QNetworkAccessManager *manager = nullptr;

        int deepseek_api_request();
        int deepseek_api_response();

        void onReplyFinished(QNetworkReply* reply);
    };

#endif // DEEPSEEK_API_SERVICES_H
