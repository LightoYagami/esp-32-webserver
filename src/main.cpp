#ifdef ESP8266
#elif defined(ESP32)
#include <WiFi.h>
#include <ESPmDNS.h>
#else
#endif



#include <ESPAsyncWebServer.h>

AsyncWebServer server(80); 

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Page Not found");
}

void setup(void)
{
  
  Serial.begin(9600);
  
  WiFi.softAP("RED", "12345678");
  Serial.println("softap");
  Serial.println("");
  Serial.println(WiFi.softAPIP());


  if (MDNS.begin("ESP")) { 
    Serial.println("MDNS responder started");
  }



  server.on("/", [](AsyncWebServerRequest * request)
  { 
   String message = "hello world"; 
  request->send(200, "text/plain", message);
  });

   server.on("/page1", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
   String message = "Welcome to page1"; 
  request->send(200, "text/plain", message);
  });

  server.onNotFound(notFound);

  server.begin();  
}


void loop(void)
{
}