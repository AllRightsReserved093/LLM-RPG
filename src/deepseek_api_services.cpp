#include "deepseek_api_services.h"

// Constructor
deepseek_api_services::deepseek_api_services() {


}


void deepseek_api_services::deepseek_api_call_perpare() {
    QJsonObject prompt;
    json_handler new_json_handler;

    prompt = new_json_handler.json_message_create("Hello");

    return;
}

int deepseek_api_services::deepseek_api_call_execute() {
    
    return 0;
}