

#include <Arduino.h>

#ifndef __OPENAI_CHAT_API_CLIENT_REQUEST_H_
#define __OPENAI_CHAT_API_CLIENT_REQUEST_H_

class OpenAIChatAPIClientRequest
{
private:
    String model = "gpt-3.5-turbo";
    String systemContent = "You are a helpful assistant.";
    String userContent = "Who won the world series in 2020?";
    
public:
    OpenAIChatAPIClientRequest(const char* model);
    ~OpenAIChatAPIClientRequest();
    void setSystemContent(const char* content);
    void setUserContent(const char* content);

    String toJSon();
};

#endif // __OPENAI_CHAT_API_CLIENT_REQUEST_H_