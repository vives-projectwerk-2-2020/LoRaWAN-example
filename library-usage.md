# How to use the lorawan-serialization and simple-lorawan libraries

## You can have a look at an example project here
[LoRaWAN example project](https://github.com/vives-projectwerk-2-2020/LoRaWAN-example/)

+ use the settings.example.h file to create your settings file
+ create an instance of the node class
+ create instance of the LoRaMessage class
+ add the values to the message object
+ then send with the Node class send method


## SimpleLoRaWAN
```
+-----------------------------------------------------+
|                        Node                         |
+-----------------------------------------------------+
|                                                     |
+-----------------------------------------------------+
|   + Node(LoRaWANKeys keys, Pinmapping pins)         |
|   + send(uint8_t* data, int size)                   |
+-----------------------------------------------------+
```

## LoRaWAN-serialization
```
+-----------------------------------------------------+
|                   LoRaMessage                       |
+-----------------------------------------------------+
|                                                     |
+-----------------------------------------------------+
|   + LoRaMessage()                                   |
|   + addUint8(int)                                   |
|   + addUint16(int)                                  |
|   + addTemperature(double)                          |
|   + addHumidity(double)                             |
|   + addPressure(double)                             |
|   + addPM(int)                                      |
+-----------------------------------------------------+
```

## Example
Send temperature, pressure, humidity, particle measure, 8 or 16 bit data:

```
#include "mbed.h"
#include "Simple-LoRaWAN.h"
#include "LoRaMessage.h"
#include "settings.h"

SimpleLoRaWAN::Node node(keys, pins);

int main(void)
{
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
```