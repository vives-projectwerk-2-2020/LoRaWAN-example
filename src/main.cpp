#include "mbed.h"
#include "Simple-LoRaWAN.h"
#include "LoRaMessage.h"
#include "settings.h"

using namespace SimpleLoRaWAN;

Serial pc(USBTX, USBRX, 115200);

Node node(keys, pins);

int main(void)
{
  pc.baud(115200);
  pc.printf("\r\n*** Starting LoRaWAN Shield Example ***\r\n");
  
  int device_id =  0x01;
  int temperature = 0x8D8; // 22 64
  int humidity = 0x2710; // decimal 100 00
  int pressure = 0x6D;
  int pm25 = 0x67;
  int pm10 = 0x91;

  while(true) {
    LoRaMessage message;
    message.addUint16(device_id);
    message.addUint16(temperature);
    message.addUint16(humidity);
    message.addUint16(pressure);
    message.addUint16(pm25);
    message.addUint16(pm10);

    node.send(message.getMessage(), message.getLength());
    //pc.printf("Message sent. counter: %d\r\n", counter);
    wait(30.0);
  }
}