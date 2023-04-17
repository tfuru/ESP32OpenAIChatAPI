#include "OpenAIChatAPIClient.h"

OpenAIChatAPIClient:: OpenAIChatAPIClient(const char* key): openaiKey(key), response("") {
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS); 
    http.setTimeout( 30 * 1000 ); 
    // http.setReuse(true);
    request = new OpenAIChatAPIClientRequest(model.c_str());
}

OpenAIChatAPIClient:: ~OpenAIChatAPIClient() {
    http.end();
    response = "";
    content = "";
    free(request);
}


String OpenAIChatAPIClient::chat(const char* prompt, const char* system) {
    // message 作る
    request->setUserContent(prompt);
    request->setSystemContent(system);

    // エンドポイント endpoint に POST
    http.begin(endpoint.c_str());
    http.addHeader("Authorization", "Bearer " + openaiKey);
    http.addHeader("Content-Type", "application/json; charset=utf-8");
    int code = http.POST(request->toJSon().c_str());
    if (code != HTTP_CODE_OK) {
        http.end();
        return "";
    }
    // int size = http.getSize();
    response = http.getString();
    http.end();
    
    // TODO response をパースして message を取り出して assistantContent に追加する
    std::string err = "";
    Json obj = Json::parse(response.c_str(), err);
    if (err == "") {
        content = String(obj["choices"][0]["message"]["content"].string_value().c_str());
        request->addAssistantContent(content.c_str());
    }

    return response;
}