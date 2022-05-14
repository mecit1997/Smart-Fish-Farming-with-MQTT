#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define pot A0

const char* ssid = "";                   // wifi ssid
const char* password =  "";         // wifi password
const char* mqttServer = "";    // Raspberry Pi IP adress 
const int   mqttPort = 1883;
const char* mqttUser = "";      // if you don't have MQTT Username, no need input
const char* mqttPassword = "";  // if you don't have MQTT Password, no need input

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

  
  int deger = analogRead(pot);
  Serial.println(deger);

  if(flag != 1 && deger >750){
    flag = 1;
    client.publish("esp8266", "Oksijen Olcum Degerleri Dusuk Lutfen Mudahale Ediniz! Havuz Numarası = 1");
    client.subscribe("esp8266");        
  }
  
  if(deger < 750) flag = 0;
  
    delay(300);
  client.loop();
}
