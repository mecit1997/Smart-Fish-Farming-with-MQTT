                              
#!/usr/bin/env python3
import subprocess
import paho.mqtt.client as mqtt
def on_connect(client, userdata, flags, rc):
    # This will be called once the client connects
    print(f"Connected with result code {rc}")
    # Subscribe here!
    client.subscribe("esp8266")
def on_message(client, userdata, msg):
    print(f"Message received [{msg.topic}]: {msg.payload}")
    if b"Oksijen Olcum" in msg.payload:
        subprocess.call(['sh','./send_gmail.sh'])
client = mqtt.Client("mqtt-test") # client ID "mqtt-test"
client.on_connect = on_connect
client.on_message = on_message
client.username_pw_set("mecid", "123")
client.connect('127.0.0.1', 1883)
client.loop_forever()
