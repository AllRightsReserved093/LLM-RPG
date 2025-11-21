#include "deepseek_api_services.h"
#include <qjsondocument.h>

// Constructor
deepseek_api_services::deepseek_api_services() {
    // 
    apiKey = qgetenv("DEEPSEEK_API_KEY");
    manager = new QNetworkAccessManager(this);
}

// Destructor
deepseek_api_services::~deepseek_api_services() {
    delete manager;
}

int deepseek_api_services::deepseek_api_call(QJsonObject message) {

    if (apiKey.isEmpty()) {
        qDebug() << "API key is not set. Please set the DEEPSEEK_API_KEY environment variable.";
        return -1;
    }

    // Define the request body
    QNetworkRequest new_request(QUrl("https://api.deepseek.com/chat/completions"));
    new_request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    new_request.setRawHeader("Authorization", "Bearer " + apiKey);

    // Get the JSON payload by calling the prepare 
    QJsonObject prompt = message;

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

// onReplyFinished: Slot to handle the finished signal
void deepseek_api_services::onReplyFinished(QNetworkReply* reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error in API call:" << reply->errorString();
        return;
    }

    // Nothing went wrong, read the response
    QByteArray response_data = reply->readAll();                // Read the response data

    std::cout << response_data.toStdString() << std::endl;
    // Send the replyReady signal with the response JSON object
    // Suppose to be receive by MainWindow::onReplyReady
    emit replyReady(response_data);

    // Clean up
    reply->deleteLater();

    return;
}
