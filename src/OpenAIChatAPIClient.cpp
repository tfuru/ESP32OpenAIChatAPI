#include "OpenAIChatAPIClient.h"


OpenAIChatAPIClient:: OpenAIChatAPIClient(const char* key): openaiKey(key) {

  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS); 
  http.setTimeout( 30 * 1000 ); 
  http.setReuse(true);
}

OpenAIChatAPIClient:: ~OpenAIChatAPIClient() {
    http.end();
}


String* OpenAIChatAPIClient::chat(const char* prompt) {
    // message を作って
    request = new OpenAIChatAPIClientRequest(model.c_str());
    request->setUserContent(prompt);
    
    // エンドポイント endpoint に POST
    http.begin(endpoint.c_str());
    http.addHeader("Authorization", "Bearer " + openaiKey);
    http.addHeader("Content-Type", "application/json; charset=utf-8");
    int code = http.POST(request->toJSon().c_str());
    if (code != HTTP_CODE_OK) {
        http.end();
        return nullptr;
    }
    // int size = http.getSize();
    response = http.getString();

    return &response;
}