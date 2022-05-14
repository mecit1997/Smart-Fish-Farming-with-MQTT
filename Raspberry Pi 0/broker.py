                              
#!/usr/bin/env python3
import subprocess
import paho.mqtt.client as mqtt
def on_connect(client, userdata, flags, rc):
    
    print(f"Connected with result code {rc}")
    # Subscribe here!
    client.subscribe("esp8266")             #subscribe olunacak topic
def on_message(client, userdata, msg):
    print(f"Message received [{msg.topic}]: {msg.payload}")   #msg.payload esp'den alinan buffer'lanan mesaj icerigi
    if b"Oksijen Olcum" in msg.payload:
        subprocess.call(['sh','./send_gmail.sh']) #mail gonderme uygulamasi
client = mqtt.Client("mqtt-test") # client ID "mqtt-test" bos birakilirsa otomatik olusturulur
client.on_connect = on_connect
client.on_message = on_message
client.username_pw_set("***", "***")  #mqtt kullanici ve sifresi burada belirlenecek olan neyse esp tarafinda da aynisi olusturulmalidir
client.connect('127.0.0.1', 1883)     #local host ve port numarasi
client.loop_forever()
