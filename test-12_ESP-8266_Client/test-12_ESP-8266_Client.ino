/*
    This sketch establishes a TCP connection to a "quote of the day" service.
    It sends a "hello" message, and then prints received data.
*/

#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "fdmxfarhan"
#define STAPSK  "fdmxfarhan"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

const char* host = "192.168.43.210";
const uint16_t port = 65432;
WiFiClient client;
void setup() {
  Serial.begin(115200);
  Serial.println("begining....");
  pinMode(2,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(16,OUTPUT);
  
  digitalWrite(2,1);
  digitalWrite(12,1);
  digitalWrite(13,1);
  digitalWrite(14,1);
  digitalWrite(16,1);
  delay(1000);
  digitalWrite(12,0);
  digitalWrite(13,0);
  digitalWrite(14,0);
  digitalWrite(16,0);
  
  
  

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
//    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(2,0);
  
  Serial.print("connecting to ");
  Serial.println(host);

  
}

void loop() {
  while(!client.connect(host, port)) {
    Serial.println("connection failed");
    delay(100);
  }
  unsigned long timeout = millis();
  while (client.available() == 0){
    Serial.print("sync: "); 
    Serial.println(client.getSync());
    delay(100);
  }

  Serial.print("received: ");
  while (client.available()) {
    char ch = static_cast<char>(client.read());
    Serial.print(ch);
    if(ch == 'N'){
      digitalWrite(12,1);
      digitalWrite(13,1);
      digitalWrite(14,1);
      digitalWrite(16,1);
      delay(1000);
      digitalWrite(12,0);
      digitalWrite(13,0);
      digitalWrite(14,0);
      digitalWrite(16,0);
      }
    else 
      digitalWrite(2,1);
  }
  Serial.println();

  delay(1000); 
}
