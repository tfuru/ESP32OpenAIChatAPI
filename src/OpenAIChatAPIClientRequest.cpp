#include "OpenAIChatAPIClientRequest.h"

OpenAIChatAPIClientRequest::OpenAIChatAPIClientRequest(const char* model): model(model) {

}

OpenAIChatAPIClientRequest::~OpenAIChatAPIClientRequest() {
    systemContent = "";
    userContent = "";
}

void OpenAIChatAPIClientRequest::setSystemContent(const char* content) {
    systemContent = content;
}

void OpenAIChatAPIClientRequest::setUserContent(const char* content) {
    userContent = content;
}

// assistantContent を追加する ループバッファ的な利用する  
void OpenAIChatAPIClientRequest::addAssistantContent(const char* content) {
    for (int i=0; i<MAX_ASSISTANT_CONTENT-1; i++) {
        assistantContent[i] = assistantContent[i+1];
    }
    assistantContent[MAX_ASSISTANT_CONTENT-1] = content;
}

String OpenAIChatAPIClientRequest::toJSon() {
    String assistants = "";
    for (int i=0; i<MAX_ASSISTANT_CONTENT; i++) {
        if (assistantContent[i] != "") {
            // assistants += "{\"role\": \"assistant\", \"content\": \"" + assistantContent[i] + "\"},";
            assistants += assistantContent[i] + " ";
        }
    }
    if (assistants.length() > 0) {
        assistants = "{\"role\": \"assistant\", \"content\": \"" + assistants + "\"},";
    }
    return "{" 
        "\"model\":\"" + model + "\"," 
        "\"messages\":" 
            "["
                "{\"role\": \"system\", \"content\": \"" + systemContent + "\"},"
                + assistants +
                "{\"role\": \"user\", \"content\": \"" + userContent + "\"}"
            "]" 
        "}";
}