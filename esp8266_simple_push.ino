#include <ESP8266WiFi.h>

constexpr auto ssid = "wifi-name";
constexpr auto password = "wifi-password";
constexpr auto host = "my-server.io";

constexpr auto sleep_in_ms = 5000;

void setup()
{
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
        delay(500);
    WiFiClient client{};
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
        Serial.println("connection failed");
        return;
    }

    client.print(String("PUSH /esp8266_simple_push") + " HTTP/1.1\r\n" +
        "Host: " + host + "\r\n" +
        "Connection: close\r\n\r\n");
    delay(10);

    ESP.deepSleep(sleep_in_ms * 1000);
}

void loop() {}