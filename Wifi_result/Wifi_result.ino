#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "SAI TEJA";
const char* password = "8555835503";
int count = 0;
void setup(){

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
  }

}

void loop()
{
  if (WiFi.status() == WL_CONNECTED)
  {
      WiFiClient client;
      HTTPClient http;
      http.begin(client, "https://api.cricapi.com/v1/cricScore?apikey=9e8bec8a-ecb9-442e-98d6-6aff3f079dfe");
      int httpCode = http.GET();
      if (httpCode > 0)
      {
        String payload = http.getString();
        const size_t bufferSize = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(8) + 370;
        DynamicJsonBuffer jsonBuffer(bufferSize);
        JsonObject& root = jsonBuffer.parseObject(http.getString());
        const char* name1 = root["description"];
        Serial.println(name1);
        //delay(10000);
      }
      http.end();
  }
}