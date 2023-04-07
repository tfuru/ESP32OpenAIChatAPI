/*
  OpenAIChatAPIClient
  Connect to a OpenAI Chat API service
  
  Copyright (C) 2023  t_furu

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Arduino.h>
#include <HTTPClient.h>
#include "OpenAIChatAPIClientRequest.h"

#ifndef __OPENAI_CHAT_API_CLIENT_H_
#define __OPENAI_CHAT_API_CLIENT_H_

class OpenAIChatAPIClient {
    public:
        OpenAIChatAPIClient(const char* key);
        ~OpenAIChatAPIClient();
        String* chat(const char* prompt);
    private:
        String model = "gpt-3.5-turbo";
        String openaiKey = "sk-";
        String endpoint = "https://api.openai.com/v1/chat/completions";
        String response = "";

        OpenAIChatAPIClientRequest* request;

        WiFiClient client;
        HTTPClient http;        
};

#endif // __OPENAI_CHAT_API_CLIENT_H_