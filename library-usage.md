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