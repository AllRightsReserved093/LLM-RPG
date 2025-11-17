#include "deepseek_api_services.h"

// Constructor
deepseek_api_services::deepseek_api_services() {
    apiKey = qgetenv("DEEPSEEK_API_KEY");

    manager = new QNetworkAccessManager(this);
}

deepseek_api_services::~deepseek_api_services() {
    delete manager;
}

int deepseek_api_services::deepseek_api_call() {

    if (apiKey.isEmpty()) {
        qDebug() << "API key is not set. Please set the DEEPSEEK_API_KEY environment variable.";
        return -1;
    }

    // Define the request body
    QNetworkRequest new_request(QUrl("https://api.deepseek.com/chat/completions"));
    new_request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    new_request.setRawHeader("Authorization", "Bearer " + apiKey);

    // Get the JSON payload by calling the prepare 
    QJsonObject prompt = deepseek_api_call_perpare();

    // Convert QJsonObject to QByteArray
    QJsonDocument doc(prompt);
    QByteArray body = doc.toJson(QJsonDocument::Compact);

    // Send the POST request
    QNetworkReply *reply = manager->post(new_request, body);

    // Connect the finished signal to a lambda function to handle the response
    // Connect(sender, signal, receiver, slot)
    //      sender:   manager = QNetworkAccessManager*, send a signal when finished
    //      signal:   &QNetworkAccessManager::finished is the signal that manager will send
    //      receiver: this = deepseek_api_services*, the receiver of the signal
    //      slot:     &deepseek_api_services::onReplyFinished is the slot that will be called when the signal is received
    // QT requires the slot to be a member function of the receiver class
    connect(manager, &QNetworkAccessManager::finished, this, &deepseek_api_services::onReplyFinished);

    return 0;
}

// -------- Helping functions ---------

QJsonObject deepseek_api_services::deepseek_api_call_perpare() {
    QJsonObject prompt;
    json_handler new_json_handler;

    prompt = new_json_handler.json_message_create("Hello");

    return prompt;
}

void deepseek_api_services::onReplyFinished(QNetworkReply* reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error in API call:" << reply->errorString();
        return;
    }

    // Nothing went wrong, read the response
    QByteArray response_data = reply->readAll();
    qDebug() << "Response received:" << response_data;

    // Clean up
    reply->deleteLater();

    return;
}