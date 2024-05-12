import serial
import paho.mqtt.client as mqtt

mqtt_broker = "localhost"
mqtt_port = 1883
mqtt_topic = "home/teste"

serial_port = "COM4" 

def on_publish(client, userdata, mid):
    print("Mensagem publicada com sucesso!")

client = mqtt.Client()
client.on_publish = on_publish
client.connect(mqtt_broker, mqtt_port)

ser = serial.Serial(serial_port, 9600)

while True:
    try:
        line = ser.readline().decode().strip()
        print("Recebido do Arduino:", line)

        client.publish(mqtt_topic, line)
    except KeyboardInterrupt:
        break

ser.close()
client.disconnect()
