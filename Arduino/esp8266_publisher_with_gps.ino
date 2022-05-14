#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h> 
#include <TinyGPSPlus.h> 

#define pot A0

float lat = 28.5458,lon = 77.1703; // enlem ve boylam degerleri icin degisken olustur
SoftwareSerial gpsSerial(3,4);//rx,tx  
TinyGPSPlus gps; // gps objesi olustur 

const char* ssid = "***";                   // wifi ssid
const char* password =  "***";         // wifi password
const char* mqttServer = "***";    // Raspberry Pi IP adress 
const int   mqttPort = 1883;
const char* mqttUser = "***";      // if you don't have MQTT Username, no need input
const char* mqttPassword = "***";  // if you don't have MQTT Password, no need input

int flag=0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {

  Serial.begin(115200);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("esp8266", mqttUser, mqttPassword )) {

      Serial.println("connected");

    } else {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);

    }
  }
  
}

void callback(char* topic, byte* payload, unsigned int length) {

  Serial.print("Message arrived in topic: ");
  Serial.println(topic);

  Serial.print("Message:");
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  Serial.println();
  Serial.println("-----------------------");

}

void loop() {
  //Serial.println("");                                 //local ipyi goruntulemek
  //Serial.print("WiFi connected - ESP IP address: ");
  //Serial.println(WiFi.localIP());
  

  if (gps.location.isUpdated())
  {
    Serial.print("LAT="); Serial.print(gps.location.lat(), 6);
    Serial.print("LNG="); Serial.println(gps.location.lng(), 6);
  }

 
String latitude = String(lat,6); 
String longitude = String(lon,6); 
Serial.println(latitude+";"+longitude);     //enlem ve boylam degerleri yazdir
delay(1000); 
  
  int deger = analogRead(pot);
  Serial.println(deger);

  if(flag != 1 && deger >750){
    flag = 1;
    client.publish("esp8266", "Oksijen Olcum Degerleri Dusuk Lutfen Mudahale Ediniz! Havuz Numarası = 1");
    client.publish("esp8266", latitude);
    //client.publish("esp8266", longitude);
    client.subscribe("esp8266");        
  }
  
  if(deger < 750) flag = 0;
  
    delay(300);
  client.loop();
}
