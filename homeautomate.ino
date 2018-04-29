#include <FirebaseArduino.h>
 #include <ESP8266WiFi.h>
char input[12];
int count=0;
int i=0;
const char* ssid     = "#Enter Wifi Ssid";
const char* password = "#Enter Wifi Password";
#define FIREBASE_HOST "enter-your-projectname.firebaseio.com"
#define FIREBASE_AUTH "enter auth key!"




int wifiStatus;

void setup() {
  
  Serial.begin(9600);
 // delay(200);
 pinMode(LED_BUILTIN, OUTPUT);
  
   WiFi.begin(ssid, password);
      
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
     Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
   
}

void loop() {
  
 
   digitalWrite(LED_BUILTIN, Firebase.getInt("redlight"));
Serial.println(Firebase.getInt("redlight"));

}
