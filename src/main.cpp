#include "mbed.h"
#include "Simple-LoRaWAN.h"
#include "LoRaMessage.h"
#include "settings.h"

Serial pc(USBTX, USBRX, 115200);

SimpleLoRaWAN::Node node(keys, pins);

int main(void)
{
  pc.baud(115200);
  pc.printf("\r\n*** Starting LoRaWAN Shield Example ***\r\n");
  
  int device_id =  0x01;
  double temperature = 22.64;
  double humidity = 95.50;
  double pressure = 15.64;
  int pm25 = 999;
  int pm10 = 245;

  while(true) {
    LoRaMessage message;
    message.addUint16(device_id);
    message.addTemperature(temperature);
    message.addHumidity(humidity);
    message.addPressure(pressure);
    message.addPM(pm25);
    message.addPM(pm10);

    node.send(message.getMessage(), message.getLength());
    wait(30.0);
  }
}