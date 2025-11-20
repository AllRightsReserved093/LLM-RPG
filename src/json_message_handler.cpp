#include "json_message_handler.h"

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


// Create the complete JSON message object
// Call json_systmes_create()
// Call json_usermes_create(user_input)
// Combine them into the final QJsonObject and return
QJsonObject json_handler::json_message_create(QString system_prompt, QString user_input) {
    QJsonObject message;

    // Set the model
    message["model"] = "deepseek-chat";

    // Create messages array
    // System message + history messages + user message
    QJsonArray messages;

    // ------ System message ------
    if (system_prompt != "empty") {
        // Reset system message if a new prompt is provided
        system_message_set(system_prompt);
        messages.append(system_message);
    }
    messages.append(system_message);

    // ------ History messages ------
    if (!history_message.isEmpty()) {
        // Append history messages if any
        messages.append(history_message);
    }
    
    // ------ User message ------
    messages.append(json_usermes_create(user_input));

    // Combine into final message object
    message["messages"] = messages;
    message["stream"] = false;

    // Save the latest user message to history
    json_save_to_history(json_usermes_create(user_input));

    return message;
}


int json_handler::json_save_to_history(QJsonObject history_message) {
    this->history_message.append(history_message);
    return 0;
}



int json_handler::json_object_save(QJsonObject json_obj, QString file_path) {
    QJsonDocument doc(json_obj);
    QByteArray byte_array = doc.toJson(QJsonDocument::Indented);

    // A QFile object, contains file path, access mode, and other file info
    // Can call open(), read(), write(), close(), etc. with it
    QFile file(file_path);
    
    // Try to open the file in write only mode, if fails, return -1
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Could not open file for writing:" << file.errorString();
        return -1;
    }

    // Write the byte array to the file
    file.write(byte_array);
    file.close();

    return 0;
}

// --------- Helping functions ---------

// Create system message JSON object
QJsonObject json_handler::json_systmes_create(QString system_prompt) {
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
