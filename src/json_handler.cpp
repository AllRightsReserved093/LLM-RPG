#include "json_handler.h"

json_handler::json_handler() {
    json_create_test();
}

// {
//     "model": "deepseek-chat",
//     "messages": [
//         {"role": "system", "content": "You are a helpful assistant"},
//         {"role": "user", "content": "Hello"}
//     ],
//     "stream": false
// }



QJsonObject json_handler::json_message_create(QString user_input) {
    QJsonObject message;

    message["model"] = "deepseek-chat";

    QJsonArray messages;
    messages.append(json_systmes_create());
    messages.append(json_usermes_create(user_input));

    message["messages"] = messages;
    message["stream"] = false;
    return message;
}

// --------- Helping functions ---------

// Create system message JSON object
QJsonObject json_handler::json_systmes_create( ) {
    QJsonObject system_message;
    system_message["role"] = "system";
    system_message["content"] = system_prompt;
    return system_message;
}

// Create user message JSON object
QJsonObject json_handler::json_usermes_create(QString user_input) {
    QJsonObject user_message;
    user_message["role"] = "user";
    user_message["content"] = user_input;
    return user_message;
}

// This is for testing and try out purposes
QJsonObject json_handler::json_create_test() {
    QJsonObject message;

    message["model"] = "deepseek-chat";

    QJsonArray messages;

    // System message
    QJsonObject system_message;
    system_message["role"] = "system";
    system_message["content"] = "You are a helpful assistant";
    messages.append(system_message);

    // User message
    QJsonObject user_message;
    user_message["role"] = "user";
    user_message["content"] = "Hello";
    messages.append(user_message);
    message["messages"] = messages;
    
    message["stream"] = false;

    return message;
}
