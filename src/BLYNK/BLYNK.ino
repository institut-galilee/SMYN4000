
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


char auth[] = "b20ddc1e0efb4833b30ce8fd57fe5721";
char ssid[] = "Maman";
char pass[] = "tkt123456";

void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);

    Serial.print(".");

}

void loop() {
  Blynk.run();

}
