

#include <Arduino.h>

#ifndef __OPENAI_CHAT_API_CLIENT_REQUEST_H_
#define __OPENAI_CHAT_API_CLIENT_REQUEST_H_

#define MAX_ASSISTANT_CONTENT 3

class OpenAIChatAPIClientRequest
{
private:
    String model = "gpt-3.5-turbo";
    String systemContent = "You are a helpful assistant.";
    String userContent = "Who won the world series in 2020?";
    String assistantContent[MAX_ASSISTANT_CONTENT];
    
public:
    OpenAIChatAPIClientRequest(const char* model);
    ~OpenAIChatAPIClientRequest();
    void setSystemContent(const char* content);
    void setUserContent(const char* content);
    void addAssistantContent(const char* content);

    String toJSon();
};

#endif // __OPENAI_CHAT_API_CLIENT_REQUEST_H_