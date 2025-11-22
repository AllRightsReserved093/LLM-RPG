#include "chatview.h"
#include "ui_chatview.h"

ChatView::ChatView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatView)
{
    ui->setupUi(this);

    // Setup JSON message handler for the chat page
    int error_code = setup_json_message_handler();
    Q_UNUSED(error_code);

    // Connect the replyReady signal from api_service_instance to the onReplyReady slot
    connect(&api_service_instance,
            &deepseek_api_services::replyReady,
            this,
            &ChatView::onReplyReady);
}

ChatView::~ChatView()
{
    delete ui;
}

int ChatView::setup_json_message_handler() {
    QString system_prompt = "test system prompt from ChatView setup";
    json_handler_instance.system_message_set(system_prompt);
    chat_view_add_new_message("system", system_prompt);
    return 0;
}

// Add new message to chat view
int ChatView::chat_view_add_new_message(QString role, QString content) {
    QString display_text = QString("[%1]: %2").arg(role, content);
    ui->chatView->append(display_text);
    return 0;
}

// Overloaded function to add new message from QJsonObject
int ChatView::chat_view_add_new_message(QJsonObject message_obj) {
    QString role = message_obj["role"].toString();
    QString content = message_obj["content"].toString();
    return chat_view_add_new_message(role, content);
}

// Get user input
// Clean input in the input field
// Append to deepseek API call message
// Call deepseek API
void ChatView::on_pushButtonEnter_clicked()
{
    // Get user input
    QString userInput = ui->inputEdit->text();

    // Clean input in the input field
    ui->inputEdit->clear();

    // Append to deepseek API call message
    QJsonObject test_json = json_handler_instance.json_message_create("empty", userInput);

    // Display user input in chat view
    chat_view_add_new_message("user", userInput);

    // Call deepseek API
    api_service_instance.deepseek_api_call(test_json);
}

// Slot to handle the reply from the API
void ChatView::onReplyReady(const QByteArray replyContent) {
    // Get the content as QJsonObject, which only include role and content
    QJsonObject assistant_message = json_handler_instance.json_get_message_from_response(replyContent);

    // Add the response to the chat history
    json_handler_instance.json_save_to_history(assistant_message);
    json_handler_instance.json_object_save(assistant_message, "C:/Users/093/Downloads/deepseek_response.json");

    // Display the content in the chat view
    chat_view_add_new_message(assistant_message);
}
