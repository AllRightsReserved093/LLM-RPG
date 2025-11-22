#ifndef CHATVIEWPAGE_H
#define CHATVIEWPAGE_H

#include <QWidget>
#include <QJsonObject>

#include "json_message_handler.h"
#include "deepseek_api_services.h"

namespace Ui {
class ChatViewPage;
}

class ChatViewPage : public QWidget
{
    Q_OBJECT

public:
    explicit ChatViewPage(QWidget *parent = nullptr);
    ~ChatViewPage();

    int chat_view_add_new_message(QString role, QString content);
    int chat_view_add_new_message(QJsonObject message_obj);

private slots:
    void on_pushButtonEnter_clicked();
    void onReplyReady(const QByteArray replyContent);

private:
    Ui::ChatViewPage *ui;

    // JSON handler instance, the main one for the chat page
    json_message_handler json_handler_instance;

    // Deepseek API service instance
    deepseek_api_services api_service_instance;

    int setup_json_message_handler();
};

#endif // CHATVIEWPAGE_H
