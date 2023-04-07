#include "OpenAIChatAPIClientRequest.h"

OpenAIChatAPIClientRequest::OpenAIChatAPIClientRequest(const char* model): model(model) {

}

OpenAIChatAPIClientRequest::~OpenAIChatAPIClientRequest() {

}

void OpenAIChatAPIClientRequest::setSystemContent(const char* content) {
    systemContent = content;
}

void OpenAIChatAPIClientRequest::setUserContent(const char* content) {
    userContent = content;
}

String OpenAIChatAPIClientRequest::toJSon() {
    return "{" 
        "\"model\":\"" + model + "\"," 
        "\"messages\":" 
            "["
                "{\"role\": \"system\", \"content\": \"" + systemContent + "\"},"
                "{\"role\": \"user\", \"content\": \"" + userContent + "\"}"
            "]" 
        "}";
}