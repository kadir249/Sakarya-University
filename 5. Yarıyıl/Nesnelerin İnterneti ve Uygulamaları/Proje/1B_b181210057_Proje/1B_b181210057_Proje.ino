//Kadir Çelik
//b181210057
//1. Öğretim B Grubu
//Akıllı Otomat Projesi

#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ESP8266HTTPClient.h>

#define FIREBASE_HOST "proje-93277-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "nzm7MIQy1lIxuQqXNGlz8pfxPLSOSCoeftflLPog"
#define WIFI_SSID "TTNET_TP-LINK_BB5C"
#define WIFI_PASSWORD "2000345767"

#define ON_Board_LED 2
#define LED_D8 15

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
}

void loop() {
    String lambaDurumu = Firebase.getString("lamba");
    if(Firebase.failed())
    {
      Serial.println("Getting /Stat failed");
      delay(500);
      return;  
    }
    digitalWrite(D2,LOW);
    if (lambaDurumu == "\"off\"")
    {
      digitalWrite(D2,LOW);
      digitalWrite(D1,HIGH);
      Serial.println("Led off");
      Serial.println();
    }
    if (lambaDurumu == "\"on\"")
    {
      digitalWrite(D2,HIGH);
      digitalWrite(D1,LOW);
      Serial.println("Led on");
      Serial.println();
      
    }

}
