# ESP32OpenAIChatAPI


# サンプルコード

必要ライブラリ  
[json11](https://github.com/dropbox/json11.git)

```
#include <json11.hpp>
using namespace json11;

#include <OpenAIChatAPIClient.h>
OpenAIChatAPIClient chatClient(OPENAI_API_KEY);

void setup() {
  Serial.begin(921600);
  // TODO WiFI 設定など

  String* respJson = chatClient.chat("元気ですか？");

  std::string err;
  Json obj = Json::parse(respJson->c_str(), err);

  // choices[0].message.content  
  String content = String(obj["choices"][0]["message"]["content"].string_value().c_str());
  Serial.println("> " + content );
  Serial.println(err.c_str());  
}
```